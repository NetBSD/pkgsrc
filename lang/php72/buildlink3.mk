# $NetBSD: buildlink3.mk,v 1.1.2.1 2018/03/03 09:23:45 spz Exp $

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=	php>=7.1.99<7.2.99
BUILDLINK_ABI_DEPENDS.php+=	php>=7.1.99<7.2.99
BUILDLINK_PKGSRCDIR.php?=	../../lang/php72

.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
