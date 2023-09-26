# $NetBSD: Makefile,v 1.1 2023/09/26 21:20:32 wiz Exp $

DISTNAME=	64tass-1.59.3120-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tass64/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/tass64/
COMMENT=	Cross-assembler for 6502-like processors
LICENSE=	gnu-gpl-v2 # or-later

USE_LANGUAGES=	c
BUILD_TARGET=	64tass

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/doc/64tass
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/64tass ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/64tass.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/64tass
	${INSTALL_DATA} ${WRKSRC}/README.html ${DESTDIR}${PREFIX}/share/doc/64tass

.include "../../mk/bsd.pkg.mk"
