# $NetBSD: buildlink3.mk,v 1.5 2018/02/05 11:21:56 jperkin Exp $

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=	php>=7.0.99<7.1.99
BUILDLINK_ABI_DEPENDS.php+=	php>=7.0.99<7.1.99
BUILDLINK_PKGSRCDIR.php?=	../../lang/php71

.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
