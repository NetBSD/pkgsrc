# $NetBSD: buildlink2.mk,v 1.2 2004/02/26 23:14:02 minskim Exp $
#
# This Makefile fragment is included by packages that use pnetC.
#
# This file was created automatically using createbuildlink 2.9.
#

.if !defined(PNETC_BUILDLINK2_MK)
PNETC_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			pnetC
BUILDLINK_DEPENDS.pnetC?=		pnetC>=0.6.0
BUILDLINK_PKGSRCDIR.pnetC?=		../../lang/pnetC

EVAL_PREFIX+=	BUILDLINK_PREFIX.pnetC=pnetC
BUILDLINK_PREFIX.pnetC_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pnetC+=	lib/cscc/lib/libc64.dll
BUILDLINK_FILES.pnetC+=	lib/cscc/lib/libm64.dll

.include "../../lang/pnet/buildlink2.mk"

BUILDLINK_TARGETS+=	pnetC-buildlink

pnetC-buildlink: _BUILDLINK_USE

.endif	# PNETC_BUILDLINK2_MK
