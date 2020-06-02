# $NetBSD: buildlink3.mk,v 1.2 2020/06/02 08:22:46 adam Exp $

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=	php>=5.6.0<5.7
BUILDLINK_ABI_DEPENDS.php+=	php>=5.6.40nb3
BUILDLINK_PKGSRCDIR.php?=	../../lang/php56

.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
