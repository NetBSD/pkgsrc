# $NetBSD: Makefile,v 1.7 2016/06/11 14:34:17 wiz Exp $

DISTNAME=	mcomix-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mcomix/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	nonakap@gmail.com
HOMEPAGE=	http://mcomix.sourceforge.net/
COMMENT=	GTK2 comic book viewer
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-gtk2>=2.12.0:../../x11/py-gtk2
DEPENDS+=	{${PYPKGPREFIX}-imaging>=1.1.5,${PYPKGPREFIX}-Pillow-[0-9]*}:../../graphics/py-imaging
DEPENDS+=	${PYPKGPREFIX}-subprocess32-[0-9]*:../../devel/py-subprocess32

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-gtk2
EGG_NAME=	${DISTNAME:S/01/1/}

PYTHON_SELF_CONFLICT=	yes

MANCOMPRESSED=	yes

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	setup.py
SUBST_SED.path=		-e s,share/man,${PKGMANDIR},g

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
