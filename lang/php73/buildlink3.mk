# $NetBSD: buildlink3.mk,v 1.3 2020/06/02 08:22:46 adam Exp $

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=	php>=7.3.0<7.3.99
BUILDLINK_ABI_DEPENDS.php+=	php>=7.3.18nb1
BUILDLINK_PKGSRCDIR.php?=	../../lang/php73

.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
