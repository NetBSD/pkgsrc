# $NetBSD: Makefile,v 1.2 2002/06/13 08:22:01 rh Exp $
#

DISTNAME=	windowmaker-desktop-1.0
CATEGORIES=	meta-pkgs x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@hispabsd.org
HOMEPAGE=	http://www.windowmaker.org/
COMMENT=	provides a desktop based on the WindowMaker wm

DEPENDS+=	windowmaker>=0.80.0:../../wm/windowmaker
DEPENDS+=	wterm-[0-9]*:../../x11/wterm
DEPENDS+=	wmextra-[0-9]*:../../wm/wmextra
DEPENDS+=	wmthemes-[0-9]*:../../wm/wmthemes
DEPENDS+=	wmakerconf-[0-9]*:../../wm/wmakerconf
DEPENDS+=	asclock-[0-9]*:../../time/asclock
DEPENDS+=	wmcpuload-[0-9]*:../../sysutils/wmcpuload
DEPENDS+=	wmmail-[0-9]*:../../mail/wmmail
DEPENDS+=	wmnet-[0-9]*:../../net/wmnet
DEPENDS+=	wmWeather-[0-9]*:../../x11/wmweather
DEPENDS+=	wmMoonClock-[0-9]*:../../time/wmmoonclock
DEPENDS+=	wmmixer-[0-9]*:../../audio/wmmixer

USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
