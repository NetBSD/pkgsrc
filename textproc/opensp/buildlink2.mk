# $NetBSD: buildlink2.mk,v 1.1 2003/09/23 06:59:24 wiz Exp $
#
# This Makefile fragment is included by packages that use opensp.
#

.if !defined(OPENSP_BUILDLINK2_MK)
OPENSP_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			opensp
BUILDLINK_DEPENDS.opensp?=		opensp>=1.5nb1
BUILDLINK_PKGSRCDIR.opensp?=		../../textproc/opensp

EVAL_PREFIX+=	BUILDLINK_PREFIX.opensp=opensp
BUILDLINK_PREFIX.opensp_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.opensp+=	include/OpenSP/*.cxx
BUILDLINK_FILES.opensp+=	include/OpenSP/*.h
BUILDLINK_FILES.opensp+=	lib/libosp.*

.include "../../devel/gettext-lib/buildlink2.mk"

BUILDLINK_TARGETS+=	opensp-buildlink

opensp-buildlink: _BUILDLINK_USE

.endif	# OPENSP_BUILDLINK2_MK
