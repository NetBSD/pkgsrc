# $NetBSD: buildlink3.mk,v 1.2 2018/12/16 22:19:54 wiz Exp $

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=	php>=7.3.0<7.3.99
BUILDLINK_ABI_DEPENDS.php+=	php>=7.3.0<7.3.99
BUILDLINK_PKGSRCDIR.php?=	../../lang/php73

.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
