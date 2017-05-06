# $NetBSD: Makefile,v 1.6 2017/05/06 00:56:50 mef Exp $

DISTNAME=	Hack-v2_020-ttf
PKGNAME=	Hack-ttf-2.020
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=chrissimpkins/}
GITHUB_PROJECT=	Hack
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourcefoundry.org/hack/
COMMENT=	Typeface designed for source code
LICENSE=	vera-ttf-license AND ofl-v1.1 # with modifications

USE_LANGUAGES=	# none
NO_BUILD=	yes

WRKSRC=		${WRKDIR}

FONTS_DIRS.ttf=		${PREFIX}/share/fonts/X11/TTF
INSTALLATION_DIRS=	${FONTS_DIRS.ttf}

do-install:
	${INSTALL_DATA} ${WRKSRC}/*ttf ${DESTDIR}/${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
