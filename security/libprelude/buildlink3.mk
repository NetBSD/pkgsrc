# $NetBSD: buildlink3.mk,v 1.12 2009/03/20 19:25:19 joerg Exp $

BUILDLINK_TREE+=	libprelude

.if !defined(LIBPRELUDE_BUILDLINK3_MK)
LIBPRELUDE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libprelude+=	libprelude>=0.9.0
BUILDLINK_ABI_DEPENDS.libprelude+=	libprelude>=0.9.16nb1
BUILDLINK_PKGSRCDIR.libprelude?=	../../security/libprelude

.include "../../security/gnutls/buildlink3.mk"
.endif # LIBPRELUDE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libprelude
