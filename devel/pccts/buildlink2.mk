# $NetBSD: buildlink2.mk,v 1.1 2002/09/12 00:25:17 wiz Exp $
#
# This Makefile fragment is included by packages that use pccts.
#
# This file was created automatically using createbuildlink 2.0.
#

.if !defined(PCCTS_BUILDLINK2_MK)
PCCTS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			pccts
BUILDLINK_DEPENDS.pccts?=		pccts>=1.33.22
BUILDLINK_PKGSRCDIR.pccts?=		../../devel/pccts
BUILDLINK_DEPMETHOD.pccts?=		"build"

EVAL_PREFIX+=	BUILDLINK_PREFIX.pccts=pccts
BUILDLINK_PREFIX.pccts_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pccts+=	include/pccts/*

BUILDLINK_TARGETS+=	pccts-buildlink

pccts-buildlink: _BUILDLINK_USE

.endif	# PCCTS_BUILDLINK2_MK
