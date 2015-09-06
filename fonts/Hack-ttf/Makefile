# $NetBSD: Makefile,v 1.1 2015/09/06 09:16:24 wiz Exp $

DISTNAME=	Hack-v2_010-ttf
PKGNAME=	Hack-ttf-2.010
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=chrissimpkins/}
GITHUB_PROJECT=	Hack
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourcefoundry.org/hack/
COMMENT=	Typeface designed for source code
LICENSE=	vera-ttf-license AND ofl-v1.1 # with modifications

WRKSRC=		${WRKDIR}

FONTS_DIRS.ttf=	${PREFIX}/share/fonts/X11/TTF
INSTALLATION_DIRS=	${FONTS_DIRS.ttf}

do-build:

do-install:
	${INSTALL_DATA} ${WRKSRC}/*ttf ${DESTDIR}/${FONTS_DIRS.ttf}

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
