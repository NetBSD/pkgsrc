# $NetBSD: buildlink3.mk,v 1.2 2004/09/14 17:18:06 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SAMBA_BUILDLINK3_MK:=	${SAMBA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	samba
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsamba}
BUILDLINK_PACKAGES+=	samba

.if !empty(SAMBA_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.samba+=	samba>=3.0.7
BUILDLINK_PKGSRCDIR.samba?=	../../net/samba
.endif	# SAMBA_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
