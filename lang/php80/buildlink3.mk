# $NetBSD: buildlink3.mk,v 1.3 2021/04/21 11:40:27 adam Exp $

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=	php>=8.0.0<9.0
BUILDLINK_ABI_DEPENDS.php+=	php>=8.0.3nb1
BUILDLINK_PKGSRCDIR.php?=	../../lang/php80

pkgbase := php
.include "../../mk/pkg-build-options.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
