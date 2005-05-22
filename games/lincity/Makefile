# $NetBSD: Makefile,v 1.16 2005/05/22 20:08:02 jlam Exp $

DISTNAME=	lincity-1.12.1
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lincity/} \
		http://www.ibiblio.org/pub/Linux/games/strategy/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://lincity.sourceforge.net/
COMMENT=	Free clone of SimCity for X11

BUILD_USES_MSGFMT=	yes

USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
GNU_CONFIGURE=		yes

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/lincity/help
	${INSTALL_DATA_DIR} ${PREFIX}/share/lincity/icons
	${INSTALL_DATA_DIR} ${PREFIX}/share/lincity/messages
	${INSTALL_DATA_DIR} ${PREFIX}/share/lincity/opening

post-install:
	${LN} -sf lincity.6 ${PREFIX}/man/man6/xlincity.6

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
