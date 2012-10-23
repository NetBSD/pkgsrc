# $NetBSD: Makefile,v 1.16 2012/10/23 19:51:34 asau Exp $
#

DISTNAME=	whowatch-1.4
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://wizard.ae.krakow.pl/~mike/download/ \
		http://janek.ae.krakow.pl/~suszyckm/download/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://wizard.ae.krakow.pl/~mike/\#whowatch
COMMENT=	Interactive who-like program displaying real-time user information

GNU_CONFIGURE=	YES

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1
INSTALL_MAKE_FLAGS+=	bindir=${DESTDIR}${PREFIX}/bin \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}	

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
