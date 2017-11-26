# $NetBSD: buildlink3.mk,v 1.4 2017/11/26 19:14:34 wiz Exp $

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=	php>=7.1.0<7.1.99
BUILDLINK_ABI_DEPENDS.php+=	php>=7.1.0<7.1.99
BUILDLINK_PKGSRCDIR.php?=	../../lang/php71

.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
