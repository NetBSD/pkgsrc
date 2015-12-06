# $NetBSD: buildlink3.mk,v 1.1 2015/12/06 15:17:31 taca Exp $

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=	php>=7.0.0<7.1
BUILDLINK_ABI_DEPENDS.php+=	php>=7.0.0<7.1
BUILDLINK_PKGSRCDIR.php?=	../../lang/php70

.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
