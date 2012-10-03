# $NetBSD: Makefile,v 1.23 2012/10/03 00:20:09 asau Exp $

DISTNAME=	base64-1.5
CATEGORIES=	converters
MASTER_SITES=	http://www.fourmilab.ch/webtools/base64/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fourmilab.ch/webtools/base64/
COMMENT=	Encode and decode base64 files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
BUILD_TARGET=		prog

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/base64 ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/base64.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
