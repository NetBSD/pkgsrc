# $NetBSD: buildlink3.mk,v 1.1 2018/12/15 17:12:44 taca Exp $

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=	php>=7.3.0<7.3.99
BUILDLINK_ABI_DEPENDS.php+=	php>=7.3.0<7.3.99
BUILDLINK_PKGSRCDIR.php?=	../../lang/php72

.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
