# $NetBSD: Makefile,v 1.6 2003/04/26 09:49:36 jmmv Exp $
#

DISTNAME=	windowmaker-desktop-1.1
CATEGORIES=	meta-pkgs x11 windowmaker
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@netbsd.org
HOMEPAGE=	http://www.windowmaker.org/
COMMENT=	provides a desktop based on the WindowMaker wm

DEPENDS+=	windowmaker>=0.80.0:../../wm/windowmaker
DEPENDS+=	wterm-[0-9]*:../../x11/wterm
DEPENDS+=	wmextra-[0-9]*:../../wm/wmextra
DEPENDS+=	wmthemes-[0-9]*:../../wm/wmthemes
DEPENDS+=	wmakerconf-[0-9]*:../../wm/wmakerconf
DEPENDS+=	asclock-[0-9]*:../../time/asclock
DEPENDS+=	wmcpuload-[0-9]*:../../sysutils/wmcpuload
DEPENDS+=	wmmemmon-[0-9]*:../../sysutils/wmmemmon
DEPENDS+=	wmmail-[0-9]*:../../mail/wmmail
DEPENDS+=	wmnet-[0-9]*:../../net/wmnet
DEPENDS+=	wmWeather-[0-9]*:../../x11/wmweather
DEPENDS+=	wmMoonClock-[0-9]*:../../time/wmmoonclock
DEPENDS+=	wmmixer-[0-9]*:../../audio/wmmixer

USE_X11=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
