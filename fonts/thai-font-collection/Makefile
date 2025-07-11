# $NetBSD: Makefile,v 1.1 2025/07/11 18:02:07 scole Exp $
#

VERSION=	1.02
DISTNAME=	${VERSION}
PKGNAME=	thai-font-collection-${VERSION}
CATEGORIES=	fonts
MASTER_SITES=	https://codeberg.org/jeffmcneill/thai-font-collection/archive/
DIST_SUBDIR=	thai-font-collection

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://codeberg.org/jeffmcneill/thai-font-collection
COMMENT=	Collection of Free and Open Source Thai Fonts
LICENSE=	apache-2.0 AND ofl-v1.1 AND gnu-gpl-v2 AND \
		dip-sipa-license AND tepc-license

WRKSRC=		${WRKDIR}/thai-font-collection

USE_LANGUAGES=	# none
NO_CONFIGURE=	yes
NO_BUILD=	yes

TTFPATH=	share/fonts/thai-font-collection

FONTS_DIRS.ttf=		${PREFIX}/${TTFPATH}
INSTALLATION_DIRS+=	${TTFPATH} share/thai-font-collection

do-install:
	${INSTALL_DATA} ${WRKSRC}/*/*/*.otf  ${DESTDIR}${PREFIX}/${TTFPATH}
	${INSTALL_DATA} ${WRKSRC}/*/*/*.ttf  ${DESTDIR}${PREFIX}/${TTFPATH}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/thai-font-collection

.include "../../mk/bsd.pkg.mk"
