# $NetBSD: buildlink3.mk,v 1.2 2026/09/02 19:04:17 wiz Exp $

BUILDLINK_TREE+=	liboauth2-apache

.if !defined(LIBOAUTH2_APACHE_BUILDLINK3_MK)
LIBOAUTH2_APACHE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liboauth2-apache+=	liboauth2-apache>=2.3.0
BUILDLINK_ABI_DEPENDS.liboauth2-apache?=		liboauth2-apache>=2.3.0nb1
BUILDLINK_PKGSRCDIR.liboauth2-apache?=		../../security/liboauth2-apache

.include "../../devel/apr/buildlink3.mk"
.include "../../devel/apr-util/buildlink3.mk"
.include "../../security/liboauth2/buildlink3.mk"
.endif	# LIBOAUTH2_APACHE_BUILDLINK3_MK

BUILDLINK_TREE+=	-liboauth2-apache
