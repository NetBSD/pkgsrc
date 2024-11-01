# $NetBSD: buildlink3.mk,v 1.7 2024/11/01 00:52:28 wiz Exp $

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=	php>=8.1.0<8.2
BUILDLINK_ABI_DEPENDS.php+=	php>=8.1.30nb1
BUILDLINK_PKGSRCDIR.php?=	../../lang/php81

pkgbase := php
.include "../../mk/pkg-build-options.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
