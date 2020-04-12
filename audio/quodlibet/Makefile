# $NetBSD: Makefile,v 1.5 2020/04/12 08:28:20 adam Exp $

DISTNAME=	quodlibet-4.3.0
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=quodlibet/}
GITHUB_PROJECT=	quodlibet
GITHUB_RELEASE=	release-${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://quodlibet.readthedocs.io/
COMMENT=	Ex Falso / Quod Libet - Music Library / Editor / Player
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-feedparser-[0-9]*:../../textproc/py-feedparser
DEPENDS+=	${PYPKGPREFIX}-gstreamer1-[0-9]*:../../multimedia/py-gstreamer1
DEPENDS+=	${PYPKGPREFIX}-mutagen-[0-9]*:../../audio/py-mutagen

USE_TOOLS+=	msgfmt

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

# Needs --desktop
_TOOLS_USE_PKGSRC.msgfmt=	yes

# Requires Python 3.5 or higher
PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/* ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 || ${TRUE}

.include "../../lang/python/distutils.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/gst-plugins1-good/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
