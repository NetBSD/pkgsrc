# $NetBSD: Makefile,v 1.13 2004/10/03 00:14:45 tv Exp $
#

DISTNAME=	lincity-1.12.0
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lincity/} \
		http://www.ibiblio.org/pub/Linux/games/strategy/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://lincity.sourceforge.net/
COMMENT=	Free clone of SimCity for X11

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
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
