# $NetBSD: buildlink3.mk,v 1.7 2021/12/08 16:02:17 adam Exp $

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=	php>=7.3.0<7.3.99
BUILDLINK_ABI_DEPENDS.php+=	php>=7.3.33
BUILDLINK_PKGSRCDIR.php?=	../../lang/php73

pkgbase := php
.include "../../mk/pkg-build-options.mk"

.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
