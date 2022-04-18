# $NetBSD: buildlink3.mk,v 1.7 2022/04/18 19:09:56 adam Exp $

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=	php>=7.4.0<7.5
BUILDLINK_ABI_DEPENDS.php+=	php>=7.4.29nb1
BUILDLINK_PKGSRCDIR.php?=	../../lang/php74

pkgbase := php
.include "../../mk/pkg-build-options.mk"

.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
