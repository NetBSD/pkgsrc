# $NetBSD: buildlink3.mk,v 1.1 2004/03/05 19:09:22 minskim Exp $
#
# This Makefile fragment is included by packages that use nbitools.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
NBITOOLS_BUILDLINK3_MK:=	${NBITOOLS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	nbitools
.endif

.if !empty(NBITOOLS_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			nbitools
BUILDLINK_DEPENDS.nbitools+=		nbitools>=6.3
BUILDLINK_PKGSRCDIR.nbitools?=		../../devel/nbitools
BUILDLINK_DEPMETHOD.nbitools?=		build

BUILDLINK_FILES.nbitools+=	lib/itools/X11/config/*

XMKMF_CMD=	${BUILDLINK_PREFIX.nbitools}/libexec/itools/xmkmf

.endif # NBITOOLS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
