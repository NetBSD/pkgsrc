# $NetBSD: Makefile,v 1.8 2019/12/11 13:18:19 mef Exp $

VERSION=	3.003
DISTNAME=	Hack-${VERSION}
PKGNAME=	Hack-ttf-${VERSION}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=chrissimpkins/}
GITHUB_PROJECT=	Hack
GITHUB_TAG=	v${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourcefoundry.org/hack/
COMMENT=	Typeface designed for source code
LICENSE=	vera-ttf-license AND ofl-v1.1 # with modifications

USE_LANGUAGES=	# none
NO_BUILD=	yes

FONTS_DIRS.ttf=		${PREFIX}/share/fonts/X11/TTF
INSTALLATION_DIRS=	${FONTS_DIRS.ttf}

do-install:
	${INSTALL_DATA} ${WRKSRC}/build/ttf/*ttf ${DESTDIR}/${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
