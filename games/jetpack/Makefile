# $NetBSD: Makefile,v 1.1 1998/08/23 11:24:52 garbled Exp $
# $FreeBSD: Makefile,v 1.16 1997/01/03 09:36:43 obrien Exp $
#

DISTNAME=	jetpack
PKGNAME=	jetpack-1.0
CATEGORIES=	games x11
MASTER_SITES=	ftp://qiclab.scn.rain.com/pub/games/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	root@garbled.net

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

post-install:
	@chown bin:games ${PREFIX}/bin/jetpack
	@chown bin:games ${PREFIX}/share/jetpack
	@chmod 2755 ${PREFIX}/bin/jetpack
	@chmod 0775 ${PREFIX}/share/jetpack
	${INSTALL_MAN} ${WRKSRC}/jetpack.man ${PREFIX}/man/man6/jetpack.6

.include "../../mk/bsd.pkg.mk"
