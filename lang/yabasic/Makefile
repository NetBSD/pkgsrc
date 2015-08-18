# $NetBSD: Makefile,v 1.18 2015/08/18 07:31:11 wiz Exp $

DISTNAME=		yabasic-2.767
PKGREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		http://www.yabasic.de/download/

MAINTAINER=		david@silicium.ath.cx
HOMEPAGE=		http://www.yabasic.de/
COMMENT=		Yet another Basic for Unix and Windows
LICENSE=		artistic OR gnu-gpl-v2

GNU_CONFIGURE=		YES
USE_NCURSES=		YES

INSTALLATION_DIRS+=	share/doc/html/yabasic

TEST_TARGET=		check

post-install:
	${INSTALL_DATA} ${WRKSRC}/yabasic.htm \
		${DESTDIR}${PREFIX}/share/doc/html/yabasic

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/ncurses/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
