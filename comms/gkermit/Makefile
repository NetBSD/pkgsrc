# $NetBSD: Makefile,v 1.27 2012/10/03 11:24:40 asau Exp $
#

DISTNAME=	gku100
PKGNAME=	gkermit-1.00
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	ftp://kermit.columbia.edu/kermit/archives/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.columbia.edu/kermit/gkermit.html
COMMENT=	Minimal implementation of the ``kermit'' protocol (GPL'd)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
BUILD_TARGET=	posix
MAKE_FILE=	makefile
MAKE_ENV+=	KFLAGS=${CFLAGS:M*:Q}

.include "../../mk/bsd.prefs.mk"

CFLAGS+=	-DERRNO_H

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/gkermit

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gkermit ${DESTDIR}${PREFIX}/bin/gkermit
	${INSTALL_MAN} ${WRKSRC}/gkermit.nr \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/gkermit.1
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/gkermit

.include "../../mk/bsd.pkg.mk"
