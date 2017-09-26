# $NetBSD: buildlink3.mk,v 1.3 2017/09/26 14:02:32 roy Exp $

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=	php>=7.0.0<7.1.0
BUILDLINK_ABI_DEPENDS.php+=	php>=7.0.0<7.1.0
BUILDLINK_PKGSRCDIR.php?=	../../lang/php70

.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
