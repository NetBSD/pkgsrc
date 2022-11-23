# $NetBSD: buildlink3.mk,v 1.3 2022/11/23 16:18:50 adam Exp $

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=	php>=8.1.0<9.0
BUILDLINK_ABI_DEPENDS.php+=	php>=8.1.12nb1
BUILDLINK_PKGSRCDIR.php?=	../../lang/php81

pkgbase := php
.include "../../mk/pkg-build-options.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
