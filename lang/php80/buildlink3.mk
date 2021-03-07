# $NetBSD: buildlink3.mk,v 1.1 2021/03/07 13:41:36 taca Exp $

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=	php>=8.0.0<9.0
BUILDLINK_ABI_DEPENDS.php+=	php>=8.0.0
BUILDLINK_PKGSRCDIR.php?=	../../lang/php80

.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
