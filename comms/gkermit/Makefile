# $NetBSD: Makefile,v 1.22 2006/09/09 02:41:55 obache Exp $
#

DISTNAME=	gku100
PKGNAME=	gkermit-1.00
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	ftp://kermit.columbia.edu/kermit/archives/

MAINTAINER=	fredb@NetBSD.org
HOMEPAGE=	http://www.columbia.edu/kermit/gkermit.html
COMMENT=	Minimal implementation of the ``kermit'' protocol (GPL'd)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
BUILD_TARGET=	posix
MAKE_FILE=	makefile
MAKE_ENV+=	KFLAGS=${CFLAGS:M*:Q}

.include "../../mk/bsd.prefs.mk"

CFLAGS+=	-DERRNO_H

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gkermit ${PREFIX}/bin/gkermit; \
	${INSTALL_MAN} ${WRKSRC}/gkermit.nr ${PREFIX}/man/man1/gkermit.1; \
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gkermit
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gkermit

.include "../../mk/bsd.pkg.mk"
