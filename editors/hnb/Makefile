# $NetBSD: Makefile,v 1.21 2007/01/07 09:13:52 rillig Exp $
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

BUILD_DIRS=		${WRKSRC}/src
BUILD_TARGET=		hnb

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/hnb ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/hnb.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
