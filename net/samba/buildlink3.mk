# $NetBSD: buildlink3.mk,v 1.3 2006/04/06 06:22:34 reed Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SAMBA_BUILDLINK3_MK:=	${SAMBA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	samba
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsamba}
BUILDLINK_PACKAGES+=	samba

.if !empty(SAMBA_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.samba+=	samba>=3.0.7
BUILDLINK_PKGSRCDIR.samba?=	../../net/samba
.endif	# SAMBA_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
