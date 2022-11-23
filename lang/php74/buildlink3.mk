# $NetBSD: buildlink3.mk,v 1.8 2022/11/23 16:18:50 adam Exp $

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=	php>=7.4.0<7.5
BUILDLINK_ABI_DEPENDS.php+=	php>=7.4.33nb1
BUILDLINK_PKGSRCDIR.php?=	../../lang/php74

pkgbase := php
.include "../../mk/pkg-build-options.mk"

.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
