# $NetBSD: buildlink3.mk,v 1.3 2020/11/05 09:06:58 ryoon Exp $

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=	php>=7.4.0<7.5
BUILDLINK_ABI_DEPENDS.php+=	php>=7.4.12nb1
BUILDLINK_PKGSRCDIR.php?=	../../lang/php74

.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
