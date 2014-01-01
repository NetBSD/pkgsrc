# $NetBSD: buildlink3.mk,v 1.16 2014/01/01 11:52:02 wiz Exp $

BUILDLINK_TREE+=	libprelude

.if !defined(LIBPRELUDE_BUILDLINK3_MK)
LIBPRELUDE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libprelude+=	libprelude>=0.9.0
BUILDLINK_ABI_DEPENDS.libprelude+=	libprelude>=0.9.24.1nb8
BUILDLINK_PKGSRCDIR.libprelude?=	../../security/libprelude

.include "../../security/gnutls/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.endif # LIBPRELUDE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libprelude
