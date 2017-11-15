# $NetBSD: buildlink3.mk,v 1.1 2017/11/15 08:56:12 jdolecek Exp $

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=	php>=7.2.0rc1<7.3
BUILDLINK_ABI_DEPENDS.php+=	php>=7.2.0rc1<7.3
BUILDLINK_PKGSRCDIR.php?=	../../lang/php72

.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
