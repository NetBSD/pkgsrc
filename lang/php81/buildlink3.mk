# $NetBSD: buildlink3.mk,v 1.1 2021/11/27 07:24:43 taca Exp $

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=	php>=8.1.0<9.0
BUILDLINK_ABI_DEPENDS.php+=	php>=8.1.0
BUILDLINK_PKGSRCDIR.php?=	../../lang/php81

pkgbase := php
.include "../../mk/pkg-build-options.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
