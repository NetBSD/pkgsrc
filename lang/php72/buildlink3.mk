# $NetBSD: buildlink3.mk,v 1.2 2018/02/05 08:51:25 jdolecek Exp $

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=	php>=7.2.2nb2<7.3
BUILDLINK_ABI_DEPENDS.php+=	php>=7.2.2nb2<7.3
BUILDLINK_PKGSRCDIR.php?=	../../lang/php72

.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
