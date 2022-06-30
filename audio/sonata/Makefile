# $NetBSD: Makefile,v 1.63 2022/06/30 11:18:03 nia Exp $

DISTNAME=	sonata-1.7b1
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=multani/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	https://github.com/multani/sonata
COMMENT=	Elegant GTK3 client for the Music Player Daemon
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-mpd2-[0-9]*:../../audio/py-mpd2
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

USE_TOOLS+=	pkg-config msgfmt

EGG_NAME=	${DISTNAME:S/sonata/Sonata/}

USE_PKG_RESOURCES=	yes

SUBST_CLASSES+=		mandir
SUBST_STAGE.mandir=	pre-configure
SUBST_VARS.mandir=	PKGMANDIR
SUBST_FILES.mandir=	setup.py

# requires python 3.2 or higher
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
