# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 22:39:33 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LINC_BUILDLINK3_MK:=	${LINC_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	linc
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlinc}
BUILDLINK_PACKAGES+=	linc
BUILDLINK_ORDER+=	linc

.if !empty(LINC_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.linc+=	linc>=1.1.1
BUILDLINK_ABI_DEPENDS.linc+=	linc>=1.1.1nb3
BUILDLINK_PKGSRCDIR.linc?=	../../net/linc
.endif	# LINC_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
