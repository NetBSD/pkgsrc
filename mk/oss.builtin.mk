# $NetBSD: oss.builtin.mk,v 1.4 2013/11/23 09:10:14 obache Exp $

BUILTIN_PKG:=	oss

BUILTIN_FIND_LIBS:=		ossaudio
BUILTIN_FIND_HEADERS_VAR:=	H_SOUNDCARD
BUILTIN_FIND_HEADERS.H_SOUNDCARD=	soundcard.h		\
					sys/soundcard.h

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.oss)
IS_BUILTIN.oss=	no
.  if empty(H_SOUNDCARD:M${LOCALBASE}/*) && empty(H_SOUNDCARD:M__nonexistent__)
IS_BUILTIN.oss=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.oss

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.oss)
# XXX
# XXX OSS support must always be native as it's provided by the OS.
# XXX
PREFER.oss=		native
.  if ${PREFER.oss} == "pkgsrc"
USE_BUILTIN.oss=	no
.  else
USE_BUILTIN.oss=	${IS_BUILTIN.oss}
.    if defined(BUILTIN_PKG.oss) && \
        !empty(IS_BUILTIN.oss:M[yY][eE][sS])
USE_BUILTIN.oss=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.oss}
.        if !empty(USE_BUILTIN.oss:M[yY][eE][sS])
USE_BUILTIN.oss!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.oss:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.oss
.endif
MAKEVARS+=	USE_BUILTIN.oss

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.oss?=	no
.if !empty(CHECK_BUILTIN.oss:M[nN][oO])

.  if !empty(USE_BUILTIN.oss:M[yY][eE][sS])
BUILDLINK_PREFIX.oss=	/usr
.    if !empty(BUILTIN_LIB_FOUND.ossaudio:M[yY][eE][sS])
BUILDLINK_LDADD.oss=	-lossaudio
.    else
BUILDLINK_LDADD.oss=	# empty
BUILDLINK_TRANSFORM+=	rm:-lossaudio
.    endif
.  endif

# Many OSS-aware programs expect <soundcard.h> to be found as either
# <sys/soundcard.h> or <machine/soundcard.h>, so create a dummy version.
# Also include <sys/ioctl.h> prior to including <soundcard.h> since we
# need definitions for _IOWR and friends.
#
BUILDLINK_TARGETS+=	buildlink-oss-soundcard-h
.PHONY: buildlink-oss-soundcard-h
buildlink-oss-soundcard-h:
	${RUN}								\
	sys_soundcard_h=${BUILDLINK_DIR}/include/sys/soundcard.h;	\
	soundcard_h=${BUILDLINK_PREFIX.oss}/include/soundcard.h;	\
	if ${TEST} ! -f $${sys_soundcard_h} -a -f $${soundcard_h}; then	\
		${ECHO_BUILDLINK_MSG} "Creating $${sys_soundcard_h}.";	\
		${MKDIR} `${DIRNAME} $${sys_soundcard_h}`;		\
		( ${ECHO} "#ifndef BUILDLINK_SYS_SOUNDCARD_H";		\
		  ${ECHO} "#define BUILDLINK_SYS_SOUNDCARD_H";		\
		  ${ECHO} "#include <sys/ioctl.h>";			\
		  ${ECHO} "#include <soundcard.h>";			\
		  ${ECHO} "#endif";					\
		) > $${sys_soundcard_h};				\
	fi;								\
	mach_soundcard_h=${BUILDLINK_DIR}/include/machine/soundcard.h;	\
	if ${TEST} ! -f $${mach_soundcard_h} -a -f $${sys_soundcard_h}; then \
		${ECHO_BUILDLINK_MSG} "Creating $${mach_soundcard_h}.";	\
		${MKDIR} `${DIRNAME} $${mach_soundcard_h}`;		\
		${LN} -s $${sys_soundcard_h} $${mach_soundcard_h};	\
	fi

.endif	# CHECK_BUILTIN.oss
