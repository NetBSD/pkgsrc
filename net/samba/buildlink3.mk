# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:11:04 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SAMBA_BUILDLINK3_MK:=	${SAMBA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	samba
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsamba}
BUILDLINK_PACKAGES+=	samba
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}samba

.if !empty(SAMBA_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.samba+=	samba>=3.0.7
BUILDLINK_PKGSRCDIR.samba?=	../../net/samba
.endif	# SAMBA_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
