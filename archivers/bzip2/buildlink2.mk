# $NetBSD: buildlink2.mk,v 1.1.2.3 2002/06/21 23:00:24 jlam Exp $

.if !defined(BZIP2_BUILDLINK2_MK)
BZIP2_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.bzip2?=	bzip2>=1.0.1
BUILDLINK_PKGSRCDIR.bzip2?=	../../archivers/bzip2

.if exists(/usr/include/bzlib.h)
#
# Recent versions of the libbz2 API prefix all functions with "BZ2_".
#
_BUILTIN_BZIP2!=	${EGREP} -c "BZ2_" /usr/include/bzlib.h || ${TRUE}
.else
_BUILTIN_BZIP2=		0
.endif

.if ${_BUILTIN_BZIP2} == "0"
_NEED_BZIP2=		YES
.else
_NEED_BZIP2=		NO
.endif

.if ${_NEED_BZIP2} == "YES"
BUILDLINK_PACKAGES+=		bzip2
EVAL_PREFIX+=			BUILDLINK_PREFIX.bzip2=bzip2
BUILDLINK_PREFIX.bzip2_DEFAULT=	${LOCALBASE}
.else
BUILDLINK_PREFIX.bzip2=		/usr
.endif

BUILDLINK_FILES.bzip2=		include/bzlib.h
BUILDLINK_FILES.bzip2+=		lib/libbz2.*

BUILDLINK_TARGETS+=		bzip2-buildlink

bzip2-buildlink: _BUILDLINK_USE

.endif	# BZIP2_BUILDLINK2_MK
