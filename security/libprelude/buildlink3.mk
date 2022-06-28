# $NetBSD: buildlink3.mk,v 1.25 2022/06/28 11:35:36 wiz Exp $

BUILDLINK_TREE+=	libprelude

.if !defined(LIBPRELUDE_BUILDLINK3_MK)
LIBPRELUDE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libprelude+=	libprelude>=0.9.0
BUILDLINK_ABI_DEPENDS.libprelude+=	libprelude>=0.9.24.1nb27
BUILDLINK_PKGSRCDIR.libprelude?=	../../security/libprelude

.include "../../security/gnutls/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.endif # LIBPRELUDE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libprelude
