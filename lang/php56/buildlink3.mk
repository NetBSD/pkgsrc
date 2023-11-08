# $NetBSD: buildlink3.mk,v 1.9 2023/11/08 13:19:51 wiz Exp $

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=	php>=5.6.0<5.7
BUILDLINK_ABI_DEPENDS.php+=	php>=5.6.40nb11
BUILDLINK_PKGSRCDIR.php?=	../../lang/php56

# XXX php?? use PKG_OPTIONS.${PHP_PKG_PREFIX}, but PKGBASE is php
pkgbase := php
.include "../../mk/pkg-build-options.mk"

.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
