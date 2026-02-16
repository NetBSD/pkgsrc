# $NetBSD: Makefile,v 1.24 2026/02/16 08:28:41 wiz Exp $

DISTNAME=	whowatch-1.4
PKGREVISION=	6
CATEGORIES=	sysutils
#MASTER_SITES=	http://wizard.ae.krakow.pl/~mike/download/
#MASTER_SITES+=	http://janek.ae.krakow.pl/~suszyckm/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://wizard.ae.krakow.pl/~mike/\#whowatch
COMMENT=	Interactive who-like program displaying real-time user information

GNU_CONFIGURE=	YES
FAKE_NCURSES=	yes

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1
INSTALL_MAKE_FLAGS+=	bindir=${DESTDIR}${PREFIX}/bin \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

CFLAGS.NetBSD+=	-D_KMEMUSER

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
