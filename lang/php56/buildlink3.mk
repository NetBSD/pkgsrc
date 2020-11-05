# $NetBSD: buildlink3.mk,v 1.3 2020/11/05 09:06:58 ryoon Exp $

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=	php>=5.6.0<5.7
BUILDLINK_ABI_DEPENDS.php+=	php>=5.6.40nb4
BUILDLINK_PKGSRCDIR.php?=	../../lang/php56

.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
