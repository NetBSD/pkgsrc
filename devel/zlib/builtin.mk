# $NetBSD: builtin.mk,v 1.19 2024/02/08 21:33:34 adam Exp $

BUILTIN_PKG:=	zlib

BUILTIN_FIND_HEADERS_VAR:=	H_ZLIB
BUILTIN_FIND_HEADERS.H_ZLIB=	zlib.h

.include "../../mk/buildlink3/bsd.builtin.mk"

.if ${MACHINE_PLATFORM:MDarwin-[0-8].*-*}
USE_BUILTIN.zlib=	no
.endif

###
### Determine if there is a built-in implementation of the package and
### set IS_BUILTIN.<pkg> appropriately ("yes" or "no").
###
.if !defined(IS_BUILTIN.zlib)
IS_BUILTIN.zlib=	no
.  if empty(H_ZLIB:M__nonexistent__) && empty(H_ZLIB:M${LOCALBASE}/*)
IS_BUILTIN.zlib=	yes
.  endif
.endif
MAKEVARS+=		IS_BUILTIN.zlib

###
### If there is a built-in implementation, then set BUILTIN_PKG.<pkg> to
### a package name to represent the built-in package.
###
.if !defined(BUILTIN_PKG.zlib) && \
    ${IS_BUILTIN.zlib:tl} == yes && \
    empty(H_ZLIB:M__nonexistent__)
BUILTIN_VERSION.zlib!=							\
	${AWK} '/\#define[ 	]*ZLIB_VERSION/ {			\
			vers = $$3;					\
			gsub("\"", "", vers);				\
			print vers;					\
		}							\
	' ${_CROSS_DESTDIR:U:Q}${H_ZLIB:Q}
BUILTIN_PKG.zlib=	zlib-${BUILTIN_VERSION.zlib:C/-[A-Za-z]*//}

.endif
MAKEVARS+=	BUILTIN_PKG.zlib

###
### Determine whether we should use the built-in implementation if it
### exists, and set USE_BUILTIN.<pkg> appropriate ("yes" or "no").
###
.if !defined(USE_BUILTIN.zlib)
.  if ${PREFER.zlib} == "pkgsrc"
USE_BUILTIN.zlib=	no
.  else
USE_BUILTIN.zlib=	${IS_BUILTIN.zlib}
.    if defined(BUILTIN_PKG.zlib) && \
        ${IS_BUILTIN.zlib:tl} == yes
USE_BUILTIN.zlib=	yes
.      for _dep_ in ${BUILDLINK_API_DEPENDS.zlib}
.        if ${USE_BUILTIN.zlib:tl} == yes
USE_BUILTIN.zlib!=	\
	if ${PKG_ADMIN} pmatch ${_dep_:Q} ${BUILTIN_PKG.zlib}; then	\
		${ECHO} yes;						\
	else								\
		${ECHO} no;						\
	fi
.        endif
.      endfor
.    endif
.  endif  # PREFER.zlib
.endif
MAKEVARS+=		USE_BUILTIN.zlib

# If USE_ZLIB is defined, then force the use of a true zlib
# implementation.
#
.if defined(USE_ZLIB)
.  if ${IS_BUILTIN.zlib:tl} == no
USE_BUILTIN.zlib=	no
.  endif
.endif

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###
CHECK_BUILTIN.zlib?=	no
.if ${CHECK_BUILTIN.zlib:tl} == no
.  if ${USE_BUILTIN.zlib:tl} == yes

BUILDLINK_TARGETS+=	fake-zlib-pc

_FAKE_ZLIB_PC=	${BUILDLINK_DIR}/lib/pkgconfig/zlib.pc

.PHONY: fake-zlib-pc
fake-zlib-pc:
	${RUN}	\
	sedsrc=../../devel/zlib/files/zlib.pc.in;	\
	src=${BUILDLINK_PREFIX.zlib:Q}/lib${LIBABISUFFIX}/pkgconfig/zlib.pc;\
	dst=${_FAKE_ZLIB_PC};					\
	${MKDIR} ${BUILDLINK_DIR}/lib/pkgconfig;\
	if [ ! -f $${dst} ]; then	\
		if [ -f $${src} ]; then	\
			${ECHO_BUILDLINK_MSG} "Symlinking $${src}";	\
			${LN} -sf $${src} $${dst};			\
		else	\
			${ECHO_BUILDLINK_MSG} "Creating $${dst}";	\
			${SED}	-e s,@prefix@,${BUILDLINK_PREFIX.zlib:Q},\
					-e s,@exec_prefix@,${BUILDLINK_PREFIX.zlib:Q},\
					-e s,@libdir@,${BUILDLINK_PREFIX.zlib:Q}/lib${LIBABISUFFIX},\
					-e s,@VERSION@,${BUILTIN_VERSION.zlib},\
					-e s,@includedir@,${BUILDLINK_PREFIX.zlib:Q}/include,\
					-e s,@sharedlibdir@,${BUILDLINK_PREFIX.zlib:Q}/lib,\
				$${sedsrc} > $${dst};			\
		fi	\
	fi
.  endif
.endif # CHECK_BUILTIN.zlib
