# $NetBSD: Makefile,v 1.24 2011/03/06 16:02:30 wiz Exp $
#

DISTNAME=	windowmaker-desktop-1.2
PKGREVISION=	4
CATEGORIES=	meta-pkgs x11 windowmaker
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.windowmaker.info/
COMMENT=	Provides a desktop based on the WindowMaker wm

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
DEPENDS+=	wmweather-[0-9]*:../../x11/wmweather
DEPENDS+=	wmMoonClock-[0-9]*:../../time/wmmoonclock
DEPENDS+=	wmmixer-[0-9]*:../../audio/wmmixer
DEPENDS+=	docker-[0-9]*:../../x11/docker

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
