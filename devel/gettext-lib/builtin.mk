# $NetBSD: builtin.mk,v 1.37 2008/01/25 14:42:27 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILTIN_PKG:=	gettext

BUILTIN_FIND_LIBS:=			intl
BUILTIN_FIND_FILES_VAR:=		H_GETTEXT _BLTN_H_GETTEXT
BUILTIN_FIND_FILES.H_GETTEXT=		/usr/include/libintl.h
BUILTIN_FIND_FILES._BLTN_H_GETTEXT=	/usr/include/libintl.h
.if ${OPSYS} != "Linux"
BUILTIN_FIND_GREP.H_GETTEXT=		\#define[ 	]*__USE_GNU_GETTEXT
.endif

.include "../../mk/buildlink3/bsd.builtin.mk"

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.gettext)
IS_BUILTIN.gettext=	no
.  if empty(H_GETTEXT:M__nonexistent__) && \
      empty(H_GETTEXT:M${LOCALBASE}/*) && \
      (!empty(BUILTIN_LIB_FOUND.intl:M[yY][eE][sS]) || ${OPSYS} == "Linux")
IS_BUILTIN.gettext=	yes
.  endif
.endif
MAKEVARS+=	IS_BUILTIN.gettext

.if !defined(BUILTIN_GETTEXT_NGETTEXT)
BUILTIN_GETTEXT_NGETTEXT=	no
.  if empty(_BLTN_H_GETTEXT:M__nonexistent__)
BUILTIN_GETTEXT_NGETTEXT!=						\
	if ${GREP} -q "char.*ngettext" ${_BLTN_H_GETTEXT:Q}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.  endif
.endif
MAKEVARS+=	BUILTIN_GETTEXT_NGETTEXT

###
### Determine whether we should use the built-in implementation if it
### exists, and uset USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.gettext)
.  if ${PREFER.gettext} == "pkgsrc"
USE_BUILTIN.gettext=	no
.  else
USE_BUILTIN.gettext=	${IS_BUILTIN.gettext}
.    if defined(BUILTIN_PKG.gettext) && \
        !empty(IS_BUILTIN.gettext:M[yY][eE][sS])
USE_BUILTIN.gettext=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.gettext}
.        if !empty(USE_BUILTIN.gettext:M[yY][eE][sS])
USE_BUILTIN.gettext!=							\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.gettext:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.    if !defined(_BLTN_REPLACE.gettext)
_BLTN_REPLACE.gettext=	no
# XXX
# XXX By default, assume that the native gettext implementation is good
# XXX enough to replace GNU gettext if it is part of glibc (the GNU C
# XXX Library).
# XXX
.      if empty(_BLTN_H_GETTEXT:M__nonexistent__)
_BLTN_REPLACE.gettext!=							\
	if ${GREP} -q "This file is part of the GNU C Library" ${_BLTN_H_GETTEXT:Q}; then \
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.      endif
.    endif
MAKEVARS+=	_BLTN_REPLACE.gettext
.    if !empty(_BLTN_REPLACE.gettext:M[yY][eE][sS])
USE_BUILTIN.gettext=	yes
.    endif
# XXX
# XXX By default, assume that the native gettext implementation is good
# XXX enough to replace GNU gettext if it supplies ngettext().
# XXX
.    if !empty(BUILTIN_GETTEXT_NGETTEXT:M[yY][eE][sS])
USE_BUILTIN.gettext=	yes
.    endif
#
# Some platforms don't have a gettext implementation that can replace
# GNU gettext.
#
_INCOMPAT_GETTEXT?=	SunOS-*-*	# XXX move to mk/platforms/SunOS.mk
.    for _pattern_ in ${_INCOMPAT_GETTEXT} ${INCOMPAT_GETTEXT}
.      if !empty(MACHINE_PLATFORM:M${_pattern_})
USE_BUILTIN.gettext=	no
.      endif
.    endfor
.  endif  # PREFER.gettext
.endif
MAKEVARS+=	USE_BUILTIN.gettext

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.gettext?=	no
.if !empty(CHECK_BUILTIN.gettext:M[nN][oO])

######################################################################
# If we are using the builtin gettext implementation...
######################################################################
.  if !empty(USE_BUILTIN.gettext:M[yY][eE][sS])
.    if ${BUILTIN_LIB_FOUND.intl} == "yes"
_BLTN_LIBINTL=		-lintl
.    else
_BLTN_LIBINTL=		# empty
BUILDLINK_TRANSFORM+=	rm:-lintl
.    endif
.  endif

######################################################################
# If we are using pkgsrc gettext implementation...
######################################################################
.  if !empty(USE_BUILTIN.gettext:M[nN][oO])
_BLTN_LIBINTL=		-lintl
_BLTN_LIBINTL+=		${BUILDLINK_LDADD.iconv}
.  endif

BUILDLINK_LDADD.gettext?=	${_BLTN_LIBINTL}

# Some GNU configure scripts generated with an older and broken gettext.m4
# fail to detect if gettext is present or not because it fails to add
# "-lintl" to the linker command line.
#
# If BROKEN_GETTEXT_DETECTION is "yes", then automatically add "-lintl"
# to LIBS to workaround this brokenness.
#
BROKEN_GETTEXT_DETECTION?=	no
.  if !empty(BROKEN_GETTEXT_DETECTION:M[yY][eE][sS])
BUILDLINK_LIBS.gettext+=	${BUILDLINK_LDADD.gettext}
CONFIGURE_ENV+=			INTLLIBS="${BUILDLINK_LDADD.gettext}"
.  endif

# If using a built-in libintl that isn't from GNU gettext, then set up
# some GNU configure variables that are checked by modern gettext.m4
# so that it will detect "GNU gettext" in the existing libintl.
#
.  if defined(GNU_CONFIGURE)
.    if !empty(USE_BUILTIN.gettext:M[yY][eE][sS])
.      if !empty(BUILTIN_LIB_FOUND.intl:M[yY][eE][sS])
CONFIGURE_ENV+=		gt_cv_func_gnugettext_libintl="yes"
CONFIGURE_ENV+=		gt_cv_func_gnugettext1_libintl="yes"
.        if !empty(BUILTIN_GETTEXT_NGETTEXT:M[yY][eE][sS])
CONFIGURE_ENV+=		gt_cv_func_gnugettext2_libintl="yes"
.        endif
.      endif
.    endif
.    if !empty(USE_BUILTIN.gettext:M[nN][oO])
CONFIGURE_ARGS+=	--with-libintl-prefix="${BUILDLINK_PREFIX.gettext}"
.    else
CONFIGURE_ARGS+=	--without-libintl-prefix
.    endif
.  endif

.endif	# CHECK_BUILTIN.gettext
