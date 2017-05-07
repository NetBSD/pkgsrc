# $NetBSD: Makefile,v 1.2 2017/05/07 02:02:10 mef Exp $

DISTNAME=	screenFetch-3.8.0
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=KittyKatt/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/KittyKatt/screenFetch/
COMMENT=	Fetches system/theme information in terminal for screenshots
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_TOOLS+=	bash:run
USE_LANGUAGES=	# none

REPLACE_BASH+=	screenfetch-dev

NO_BUILD=	yes

# These are optional, however the purpose of screenfetch is to make use of them
DEPENDS+=	curl-[0-9]*:../../www/curl
DEPENDS+=	scrot-[0-9]*:../../graphics/scrot

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${RUN} cd ${WRKSRC} && ${INSTALL_SCRIPT} screenfetch-dev \
		${DESTDIR}${PREFIX}/bin/screenfetch
	${RUN} cd ${WRKSRC} && ${INSTALL_DATA} screenfetch.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/screenfetch.1

.include "../../mk/bsd.pkg.mk"
