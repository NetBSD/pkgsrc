# $NetBSD: buildlink3.mk,v 1.1 2022/12/11 14:12:29 taca Exp $

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=	php>=8.2.0<9.0
BUILDLINK_ABI_DEPENDS.php+=	php>=8.2.0
BUILDLINK_PKGSRCDIR.php?=	../../lang/php82

pkgbase := php
.include "../../mk/pkg-build-options.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
