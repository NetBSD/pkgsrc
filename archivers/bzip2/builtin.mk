# $NetBSD: builtin.mk,v 1.1 2004/03/10 17:57:14 jlam Exp $

.if !defined(IS_BUILTIN.bzip2)
IS_BUILTIN.bzip2=	no
.  if exists(/usr/include/bzlib.h)
IS_BUILTIN.bzip2!=							\
	if ${GREP} -q "BZ2_" /usr/include/bzlib.h; then			\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
.  endif
MAKEFLAGS+=	IS_BUILTIN.bzip2=${IS_BUILTIN.bzip2}
.endif

CHECK_BUILTIN.bzip2?=	no
.if !empty(CHECK_BUILTIN.bzip2:M[yY][eE][sS])
USE_BUILTIN.bzip2=	yes
.endif

.if !defined(USE_BUILTIN.bzip2)
USE_BUILTIN.bzip2?=	${IS_BUILTIN.bzip2}
PREFER.bzip2?=		pkgsrc

.  if defined(USE_BZIP2)
.    if !empty(IS_BUILTIN.bzip2:M[nN][oO]) || \
        (${PREFER.bzip2} == "pkgsrc")
USE_BUILTIN.bzip2=	no
.    endif
.  endif

# Solaris 9 has bzip2 1.0.1, build it on older versions.
# Darwin only has a static libbz2.a.
#
_INCOMPAT_BZIP2?=	SunOS-5.[678]-* Darwin-*
.  for _pattern_ in ${_INCOMPAT_BZIP2} ${INCOMPAT_BZIP2}
.    if !empty(MACHINE_PLATFORM:M${_pattern_})
USE_BUILTIN.bzip2=	no
.    endif
.  endfor
.endif	# USE_BUILTIN.bzip2
