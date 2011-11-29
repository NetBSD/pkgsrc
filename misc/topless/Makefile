# $NetBSD: Makefile,v 1.2 2011/11/29 18:22:05 hans Exp $
#

DISTNAME=	topless-1.52
CATEGORIES=	misc sysutils
MASTER_SITES=	http://people.freebsd.org/~daichi/src/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://bloghome.lovepeers.org/daymemo2/files/2005/0613/topless.html
COMMENT=	Display command output on the whole screen like ``top''
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	perl pod2man

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/topless ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/topless.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
