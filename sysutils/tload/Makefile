# $NetBSD: Makefile,v 1.10 2011/03/18 20:51:26 zafer Exp $
#

DISTNAME=	procps-2.0.6
PKGNAME=	tload-2.0.6
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://procps.sourceforge.net/

MAINTAINER=	hubertf@NetBSD.org
COMMENT=	Terminal version of xload
HOMEPAGE=	http://procps.sourceforge.net/

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC} ; \
	${CC} ${CFLAGS} tload.c -o tload

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tload ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tload.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
