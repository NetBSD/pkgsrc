# $NetBSD: Makefile,v 1.18 2025/04/24 14:14:43 wiz Exp $
#

DISTNAME=		fl_logbook-2.5
PKGREVISION=		8
CATEGORIES=		ham
MASTER_SITES=		http://www.w1hkj.com/LinuxApps/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.w1hkj.org/
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
