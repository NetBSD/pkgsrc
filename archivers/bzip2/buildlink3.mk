# $NetBSD: buildlink3.mk,v 1.1 2004/01/03 23:06:43 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
BZIP2_BUILDLINK3_MK:=	${BZIP2_BUILDLINK3_MK}+

.if !empty(BZIP2_BUILDLINK3_MK:M\+)
.  include "../../mk/bsd.prefs.mk"

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
_NEED_BZIP2=	YES
.endif

.if !empty(BUILDLINK_CHECK_BUILTIN.bzip2:M[yY][eE][sS])
_NEED_BZIP2=	NO
.endif

.if !defined(_NEED_BZIP2)
.  if !empty(BUILDLINK_IS_BUILTIN.bzip2:M[nN][oO])
_NEED_BZIP2=	YES
.  else
_NEED_BZIP2=	NO
#
# Solaris 9 has bzip2 1.0.1, build it on older versions.
# Darwin only has static libbz2.a, which can't be buildlinked.
#
_INCOMPAT_BZIP2=	SunOS-5.[678]-* Darwin-*
INCOMPAT_BZIP2?=	# empty
.    for _pattern_ in ${_INCOMPAT_BZIP2} ${INCOMPAT_BZIP2}
.      if !empty(MACHINE_PLATFORM:M${_pattern_})
_NEED_BZIP2=	YES
.      endif
.    endfor
.  endif
MAKEFLAGS+=	_NEED_BZIP2="${_NEED_BZIP2}"
.endif

.if ${_NEED_BZIP2} == "YES"
.  if !empty(BUILDLINK_DEPTH:M\+)
BUILDLINK_DEPENDS+=	bzip2
.  endif
.endif

.if !empty(BZIP2_BUILDLINK3_MK:M\+)
.  if ${_NEED_BZIP2} == "YES"
BUILDLINK_PACKAGES+=		bzip2
.  else
BUILDLINK_PREFIX.bzip2=		/usr
.  endif
.endif	# BZIP2_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:C/\+$//}
