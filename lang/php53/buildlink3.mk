# $NetBSD: buildlink3.mk,v 1.3 2012/06/16 05:24:10 taca Exp $

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=	php>=5.3.2<5.4
BUILDLINK_ABI_DEPENDS.php+=	php>=5.3.13nb3<5.4
BUILDLINK_PKGSRCDIR.php?=	../../lang/php53

.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
