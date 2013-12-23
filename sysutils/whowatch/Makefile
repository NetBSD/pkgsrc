# $NetBSD: Makefile,v 1.19 2013/12/23 11:57:06 wiz Exp $

DISTNAME=	whowatch-1.4
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://wizard.ae.krakow.pl/~mike/download/ \
		http://janek.ae.krakow.pl/~suszyckm/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wizard.ae.krakow.pl/~mike/\#whowatch
COMMENT=	Interactive who-like program displaying real-time user information

GNU_CONFIGURE=	YES

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1
INSTALL_MAKE_FLAGS+=	bindir=${DESTDIR}${PREFIX}/bin \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

CFLAGS.NetBSD+=	-D_KMEMUSER

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
