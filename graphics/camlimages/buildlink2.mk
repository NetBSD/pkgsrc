# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/08/31 01:24:41 jtb Exp $
#
# This Makefile fragment is included by packages that use camlimages.

.if !defined(CAMLIMAGES_BUILDLINK2_MK)
CAMLIMAGES_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			camlimages
BUILDLINK_DEPENDS.camlimages?=		camlimages>=2.11
BUILDLINK_PKGSRCDIR.camlimages?=	../../graphics/camlimages

EVAL_PREFIX+=	BUILDLINK_PREFIX.camlimages=camlimages
BUILDLINK_PREFIX.camlimages_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.camlimages+=	lib/ocaml/camlimages/*

BUILDLINK_TARGETS+=	camlimages-buildlink

camlimages-buildlink: _BUILDLINK_USE

.endif	# CAMLIMAGES_BUILDLINK2_MK
