# $NetBSD: Makefile,v 1.34 2026/01/27 08:39:48 wiz Exp $

DISTNAME=	mcomix-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mcomix/}

MAINTAINER=	nonakap@gmail.com
HOMEPAGE=	https://mcomix.sourceforge.net/
COMMENT=	GTK+ comic book viewer
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-Pillow>=6.0.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-gobject3>=3.36.0:../../devel/py-gobject3

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

MANCOMPRESSED=	yes

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	setup.py
SUBST_SED.path=		-e s,share/man,${PKGMANDIR},g

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
