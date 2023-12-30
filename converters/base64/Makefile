# $NetBSD: Makefile,v 1.26 2023/12/30 01:53:28 zafer Exp $

DISTNAME=	base64-1.5
CATEGORIES=	converters
MASTER_SITES=	https://www.fourmilab.ch/webtools/base64/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.fourmilab.ch/webtools/base64/
COMMENT=	Encode and decode base64 files

GNU_CONFIGURE=		yes
BUILD_TARGET=		prog

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/base64 ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/base64.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
