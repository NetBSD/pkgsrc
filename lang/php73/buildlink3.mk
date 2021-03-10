# $NetBSD: buildlink3.mk,v 1.5 2021/03/10 16:35:16 nia Exp $

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=	php>=7.3.0<7.3.99
BUILDLINK_ABI_DEPENDS.php+=	php>=7.3.24nb1
BUILDLINK_PKGSRCDIR.php?=	../../lang/php73

pkgbase := php
.include "../../mk/pkg-build-options.mk"

.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
