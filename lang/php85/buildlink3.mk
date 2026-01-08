# $NetBSD: buildlink3.mk,v 1.1 2026/01/08 13:38:00 taca Exp $

BUILDLINK_TREE+=	php85

.if !defined(PHP85_BUILDLINK3_MK)
PHP85_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php85+=	php85>=8.5.0<8.6
BUILDLINK_ABI_DEPENDS.php85+=	php85>=8.5.1
BUILDLINK_PKGSRCDIR.php85?=	../../lang/php85
BUILDLINK_INCDIRS.php85+=	${PHP_INCDIR}

pkgbase := php85
.include "../../mk/pkg-build-options.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP85_BUILDLINK3_MK

BUILDLINK_TREE+=	-php85
