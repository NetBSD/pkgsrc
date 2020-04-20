# $NetBSD: Makefile,v 1.13 2020/04/20 00:39:36 joerg Exp $
#

DISTNAME=		fl_logbook-2.5
PKGREVISION=		4
CATEGORIES=		ham
MASTER_SITES=		http://www.w1hkj.com/LinuxApps/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.w1hkj.com/
COMMENT=		FLTK-based amateur radio log book
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c++
USE_TOOLS+=		gmake

MAKE_FILE=		makefile

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fl_logbook ${DESTDIR}${PREFIX}/bin

.include "../../x11/fltk13/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
