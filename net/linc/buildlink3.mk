# $NetBSD: buildlink3.mk,v 1.21 2025/10/23 20:38:51 wiz Exp $

BUILDLINK_TREE+=	linc

.if !defined(LINC_BUILDLINK3_MK)
LINC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.linc+=	linc>=1.1.1
BUILDLINK_ABI_DEPENDS.linc+=	linc>=1.1.1nb19
BUILDLINK_PKGSRCDIR.linc?=	../../net/linc

.include "../../devel/glib2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # LINC_BUILDLINK3_MK

BUILDLINK_TREE+=	-linc
