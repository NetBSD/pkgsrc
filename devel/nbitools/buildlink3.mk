# $NetBSD: buildlink3.mk,v 1.2 2004/03/05 21:08:52 minskim Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
NBITOOLS_BUILDLINK3_MK:=	${NBITOOLS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	nbitools
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nnbitools}
BUILDLINK_PACKAGES+=	nbitools

.if !empty(NBITOOLS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.nbitools+=	nbitools>=6.3
BUILDLINK_PKGSRCDIR.nbitools?=	../../devel/nbitools
BUILDLINK_DEPMETHOD.nbitools?=	build

BUILDLINK_FILES.nbitools+=	lib/itools/X11/config/*

XMKMF_CMD=	${BUILDLINK_PREFIX.nbitools}/libexec/itools/xmkmf

.endif	# NBITOOLS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
