# $NetBSD: buildlink3.mk,v 1.9 2023/11/08 13:19:51 wiz Exp $

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=	php>=8.0.0<8.1
BUILDLINK_ABI_DEPENDS.php+=	php>=8.0.30nb2
BUILDLINK_PKGSRCDIR.php?=	../../lang/php80

pkgbase := php
.include "../../mk/pkg-build-options.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
