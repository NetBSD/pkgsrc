# $NetBSD: Makefile,v 1.35 2018/11/14 22:21:20 kleink Exp $

PY_PATCHPLIST=	yes
EGG_NAME?=	${DISTNAME:C/-([^0-9])/_\1/g}
PLIST_SUBST+=	EGG_FILE=${EGG_NAME}-py${PYVERSSUFFIX}.egg-info

PKGREVISION= 1
.include "Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//:S/-/3-/}

COMMENT=	Python bindings for glib2 gobject

CONFIGURE_ARGS+=	--without-common
TEST_TARGET=		check

.include "../../devel/py-gobject3-common/buildlink3.mk"
# https://bugzilla.gnome.org/show_bug.cgi?id=685094
# https://bugzilla.gnome.org/show_bug.cgi?id=707196
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
