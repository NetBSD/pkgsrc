# $NetBSD: buildlink3.mk,v 1.7 2022/11/23 16:18:50 adam Exp $

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=	php>=5.6.0<5.7
BUILDLINK_ABI_DEPENDS.php+=	php>=5.6.40nb8
BUILDLINK_PKGSRCDIR.php?=	../../lang/php56

# XXX php?? use PKG_OPTIONS.${PHP_PKG_PREFIX}, but PKGBASE is php
pkgbase := php
.include "../../mk/pkg-build-options.mk"

.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
