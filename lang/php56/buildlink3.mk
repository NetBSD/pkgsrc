# $NetBSD: buildlink3.mk,v 1.14 2025/04/17 21:51:22 wiz Exp $

BUILDLINK_TREE+=	php56

.if !defined(PHP56_BUILDLINK3_MK)
PHP56_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php56+=	php${PHP_VER}>=5.6.0<5.7
BUILDLINK_ABI_DEPENDS.php56+=	php56>=5.6.40nb1
BUILDLINK_PKGSRCDIR.php56?=	../../lang/php56
BUILDLINK_INCDIRS.php56+=	${PHP_INCDIR}

pkgbase := php56
.include "../../mk/pkg-build-options.mk"

.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP56_BUILDLINK3_MK

BUILDLINK_TREE+=	-php56
