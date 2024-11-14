# $NetBSD: buildlink3.mk,v 1.4 2024/11/14 22:20:30 wiz Exp $

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=	php>=8.3.0<8.4
BUILDLINK_ABI_DEPENDS.php+=	php>=8.3.13nb4
BUILDLINK_PKGSRCDIR.php?=	../../lang/php83

pkgbase := php
.include "../../mk/pkg-build-options.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
