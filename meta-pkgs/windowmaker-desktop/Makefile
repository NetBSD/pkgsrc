# $NetBSD: Makefile,v 1.14 2005/01/28 00:00:14 ben Exp $
#

DISTNAME=	windowmaker-desktop-1.2
CATEGORIES=	meta-pkgs x11 windowmaker
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.windowmaker.org/
COMMENT=	Provides a desktop based on the WindowMaker wm

DEPENDS+=	windowmaker>=0.80.0:../../wm/windowmaker
DEPENDS+=	wterm-[0-9]*:../../x11/wterm
DEPENDS+=	wmextra-[0-9]*:../../wm/wmextra
DEPENDS+=	wmthemes-[0-9]*:../../wm/wmthemes
DEPENDS+=	wmakerconf-[0-9]*:../../wm/wmakerconf
DEPENDS+=	asclock-[0-9]*:../../time/asclock
DEPENDS+=	wmcpuload-[0-9]*:../../sysutils/wmcpuload
DEPENDS+=	wmdrawer-[0-9]*:../../wm/wmdrawer
DEPENDS+=	wmmemmon-[0-9]*:../../sysutils/wmmemmon
DEPENDS+=	wmmail-[0-9]*:../../mail/wmmail
DEPENDS+=	wmnet-[0-9]*:../../net/wmnet
DEPENDS+=	wmweather-[0-9]*:../../x11/wmweather
DEPENDS+=	wmMoonClock-[0-9]*:../../time/wmmoonclock
DEPENDS+=	wmmixer-[0-9]*:../../audio/wmmixer

USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
