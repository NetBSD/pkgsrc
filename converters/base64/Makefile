# $NetBSD: Makefile,v 1.19 2006/12/19 13:34:56 rillig Exp $
#

DISTNAME=	base64-1.3
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://www.fourmilab.ch/webtools/base64/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fourmilab.ch/webtools/base64/
COMMENT=	Encode and decode base64 files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes
BUILD_TARGET=	prog

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/base64 ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/base64.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
