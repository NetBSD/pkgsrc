# $NetBSD: Makefile,v 1.17 2004/12/03 15:14:52 wiz Exp $
#

DISTNAME=	gkermit
PKGNAME=	gkermit-1.00
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	ftp://kermit.columbia.edu/kermit/archives/

MAINTAINER=	fredb@NetBSD.org
HOMEPAGE=	http://www.columbia.edu/kermit/gkermit.html
COMMENT=	Minimal implementation of the ``kermit'' protocol (GPL'd)

DIST_SUBDIR=	gkermit-1.00

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
USE_BUILDLINK3=	yes
BUILD_TARGET=	posix
MAKEFILE=	makefile
MAKE_ENV+=	KFLAGS="${CFLAGS}"

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gkermit ${PREFIX}/bin/gkermit; \
	${INSTALL_MAN} ${WRKSRC}/gkermit.nr ${PREFIX}/man/man1/gkermit.1; \
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gkermit
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gkermit

.include "../../mk/bsd.pkg.mk"
