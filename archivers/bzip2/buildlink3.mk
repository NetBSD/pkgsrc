# $NetBSD: buildlink3.mk,v 1.3 2004/01/05 09:31:31 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
BZIP2_BUILDLINK3_MK:=	${BZIP2_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BZIP2_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		bzip2
BUILDLINK_DEPENDS.bzip2?=	bzip2>=1.0.1
BUILDLINK_PKGSRCDIR.bzip2?=	../../archivers/bzip2
.endif	# BZIP2_BUILDLINK3_MK

BUILDLINK_CHECK_BUILTIN.bzip2?=	NO

.if !defined(BUILDLINK_IS_BUILTIN.bzip2)
BUILDLINK_IS_BUILTIN.bzip2=	NO
.  if exists(/usr/include/bzlib.h)
BUILDLINK_IS_BUILTIN.bzip2!=						\
	if ${GREP} -q "BZ2_" /usr/include/bzlib.h; then			\
		${ECHO} YES;						\
	else								\
		${ECHO} NO;						\
	fi
.  endif
MAKEFLAGS+=	BUILDLINK_IS_BUILTIN.bzip2=${BUILDLINK_IS_BUILTIN.bzip2}
.endif

.if defined(USE_BZIP2)
BUILDLINK_USE_BUILTIN.bzip2=	NO
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.bzip2:M[yY][eE][sS])
BUILDLINK_USE_BUILTIN.bzip2=	YES
.endif

.if !defined(BUILDLINK_USE_BUILTIN.bzip2)
.  if !empty(BUILDLINK_IS_BUILTIN.bzip2:M[nN][oO])
BUILDLINK_USE_BUILTIN.bzip2=	NO
.  else
BUILDLINK_USE_BUILTIN.bzip2=	YES
#
# Solaris 9 has bzip2 1.0.1, build it on older versions.
# Darwin only has static libbz2.a, which can't be buildlinked.
#
_INCOMPAT_BZIP2=	SunOS-5.[678]-* Darwin-*
INCOMPAT_BZIP2?=	# empty
.    for _pattern_ in ${_INCOMPAT_BZIP2} ${INCOMPAT_BZIP2}
.      if !empty(MACHINE_PLATFORM:M${_pattern_})
BUILDLINK_USE_BUILTIN.bzip2=	NO
.      endif
.    endfor
.  endif
MAKEFLAGS+=	BUILDLINK_USE_BUILTIN.bzip2="${BUILDLINK_USE_BUILTIN.bzip2}"
.endif

.if !empty(BUILDLINK_USE_BUILTIN.bzip2:M[nN][oO])
.  if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	bzip2
.  endif
.endif

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:C/\+$//}
