# $NetBSD: Makefile,v 1.24 2019/10/12 20:05:59 rillig Exp $

DISTNAME=		yabasic-2.79.2
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		http://www.yabasic.de/download/

MAINTAINER=		david@silicium.ath.cx
HOMEPAGE=		http://www.yabasic.de/
COMMENT=		Yet another Basic for Unix and Windows
LICENSE=		artistic OR gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_NCURSES=		yes
AUTO_MKDIRS=		yes

TEST_TARGET=		check

post-install:
	${INSTALL_DATA} ${WRKSRC}/yabasic.htm \
		${DESTDIR}${PREFIX}/share/doc/yabasic

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/ncurses/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
