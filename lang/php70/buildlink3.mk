# $NetBSD: buildlink3.mk,v 1.2 2016/08/05 08:29:01 wiz Exp $

BUILDLINK_TREE+=	php

.if !defined(PHP_BUILDLINK3_MK)
PHP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php+=	php>=7.0.0<7.1.0beta1
BUILDLINK_ABI_DEPENDS.php+=	php>=7.0.0<7.1.0beta1
BUILDLINK_PKGSRCDIR.php?=	../../lang/php70

.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP_BUILDLINK3_MK

BUILDLINK_TREE+=	-php
