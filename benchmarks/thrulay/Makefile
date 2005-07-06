# $NetBSD: Makefile,v 1.1.1.1 2005/07/06 19:42:01 reed Exp $

DISTNAME=	thrulay-0.6
CATEGORIES=	benchmarks net
MASTER_SITES=	http://www.internet2.edu/~shalunov/thrulay/

MAINTAINER=	rpaulo@NetBSD.org
HOMEPAGE=	http://www.internet2.edu/~shalunov/thrulay/
COMMENT=	TCP and UDP network capacity tester

ONLY_FOR_PLATFORM=	DragonFly-*-i386 FreeBSD-*-i386 Linux-*-i386 \
			NetBSD-*-i386

PKG_INSTALLATION_TYPES=	overwrite pkgviews

INSTALLATION_DIRS=	bin share/doc/thrulay

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/thrulayd ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/thrulay ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README \
		${PREFIX}/share/doc/thrulay
	${INSTALL_DATA} ${WRKSRC}/thrulay-protocol.txt \
		${PREFIX}/share/doc/thrulay

.include "../../mk/bsd.pkg.mk"
