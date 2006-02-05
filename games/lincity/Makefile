# $NetBSD: Makefile,v 1.18 2006/02/05 23:09:20 joerg Exp $

DISTNAME=	lincity-1.12.1
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lincity/} \
		http://www.ibiblio.org/pub/Linux/games/strategy/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://lincity.sourceforge.net/
COMMENT=	Free clone of SimCity for X11

BUILD_USES_MSGFMT=	yes

USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/lincity/help
	${INSTALL_DATA_DIR} ${PREFIX}/share/lincity/icons
	${INSTALL_DATA_DIR} ${PREFIX}/share/lincity/messages
	${INSTALL_DATA_DIR} ${PREFIX}/share/lincity/opening

post-install:
	${LN} -sf lincity.6 ${PREFIX}/man/man6/xlincity.6

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
