# $NetBSD: Makefile,v 1.1 2025/01/22 13:06:47 nat Exp $
#

VERSION=	1.2
GITHUB_PROJECT=	ansi2text
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	${GITHUB_PROJECT}-${VERSION}
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GITHUB:=AceHusky12/}
EXTRACT_SUFX=	.zip

MAINTAINER=	nat@NetBSD.org
HOMEPAGE=	https://github.com/AceHusky12/ansi2text
COMMENT=	Utility for formatting ansi sequences for display with less
LICENSE=	2-clause-bsd

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ansi2text ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ansi2text.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
