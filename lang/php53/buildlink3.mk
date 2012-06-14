# $NetBSD: buildlink3.mk,v 1.2 2012/06/14 07:43:11 sbd Exp $

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=	php>=5.3.2
BUILDLINK_ABI_DEPENDS.php+=	php>=5.3.13nb3
BUILDLINK_PKGSRCDIR.php?=	../../lang/php53

.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
