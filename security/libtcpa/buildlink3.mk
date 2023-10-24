# $NetBSD: buildlink3.mk,v 1.18 2023/10/24 22:10:51 wiz Exp $

BUILDLINK_TREE+=	libtcpa

.if !defined(LIBTCPA_BUILDLINK3_MK)
LIBTCPA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtcpa+=	libtcpa>=1.1b
BUILDLINK_ABI_DEPENDS.libtcpa+=	libtcpa>=1.1bnb9
BUILDLINK_PKGSRCDIR.libtcpa?=	../../security/libtcpa
BUILDLINK_DEPMETHOD.libtcpa?=	build

.include "../../security/openssl/buildlink3.mk"
.endif # LIBTCPA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtcpa
