# $NetBSD: buildlink3.mk,v 1.1 2004/04/15 16:28:11 jmmv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SAMBA_BUILDLINK3_MK:=	${SAMBA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	samba
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsamba}
BUILDLINK_PACKAGES+=	samba

.if !empty(SAMBA_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.samba+=	samba>=3.0.2anb1
BUILDLINK_PKGSRCDIR.samba?=	../../net/samba
.endif	# SAMBA_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
