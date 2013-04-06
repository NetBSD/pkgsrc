# $NetBSD: Makefile,v 1.24 2013/04/06 15:46:36 rodent Exp $
#

DISTNAME=	hnb-1.9.17
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hnb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hnb.sourceforge.net/
COMMENT=	Hierarchical data organizer

INCOMPAT_CURSES=	NetBSD-1.5*-* NetBSD-1.6[-_.]*-* NetBSD-1.6[A-U]-*

USE_TOOLS+=		gmake

BUILD_DIRS=		src
BUILD_TARGET=		hnb

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/hnb ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/hnb.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
