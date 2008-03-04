# $NetBSD: Makefile,v 1.10 2008/03/04 06:59:06 jlam Exp $
#

DISTNAME=		xsc-1.5
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		http://www.panix.com/~mbh/xsc/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.panix.com/~mbh/xsc/
COMMENT=		Star Castle clone

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xsc ${DESTDIR}${PREFIX}/bin/xsc
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/xsc
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/xsc

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
