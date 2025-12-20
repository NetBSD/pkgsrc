# $NetBSD: Makefile,v 1.28 2025/12/20 16:27:34 nia Exp $

DISTNAME=	windowmaker-desktop-1.4
CATEGORIES=	meta-pkgs x11 windowmaker
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.windowmaker.info/
COMMENT=	Provides a desktop based on the WindowMaker wm

META_PACKAGE=	yes

DEPENDS+=	windowmaker>=0.80.0:../../wm/windowmaker
DEPENDS+=	wterm-[0-9]*:../../x11/wterm
DEPENDS+=	wmextra-[0-9]*:../../wm/wmextra
DEPENDS+=	wmakerconf-[0-9]*:../../wm/wmakerconf
DEPENDS+=	asclock-[0-9]*:../../time/asclock
DEPENDS+=	wmcpuload-[0-9]*:../../sysutils/wmcpuload
DEPENDS+=	wmmemmon-[0-9]*:../../sysutils/wmmemmon
DEPENDS+=	wmmail-[0-9]*:../../mail/wmmail
DEPENDS+=	wmweather-[0-9]*:../../x11/wmweather
DEPENDS+=	wmMoonClock-[0-9]*:../../time/wmmoonclock
.include "../../mk/oss.buildlink3.mk"
.if ${OSS_TYPE} != "none"
DEPENDS+=	wmmixer-[0-9]*:../../audio/wmmixer
.endif
DEPENDS+=	docker-[0-9]*:../../x11/docker

.include "../../mk/bsd.pkg.mk"
