# $NetBSD: Makefile,v 1.47 2012/07/15 08:22:51 wiz Exp $

META_PACKAGE=	yes

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-extras-${XFCE4_VERSION}
PKGREVISION=	17
CATEGORIES=	meta-pkgs
COMMENT=	Xfce extras

# Xfce
.include "../../meta-pkgs/xfce4/buildlink3.mk"

#
# Do you want to have more plugins? See http://goodies.xfce.org/releases/
# for all available plugins...
#

# Additional plugins etc.

DEPENDS+=	ristretto-[0-9]*:../../graphics/ristretto

.include "../../audio/xfce4-xmms-plugin/buildlink3.mk"
.include "../../misc/xfce4-weather-plugin/buildlink3.mk"
.include "../../net/xfce4-wavelan-plugin/buildlink3.mk"
.include "../../multimedia/xfce4-mpc-plugin/buildlink3.mk"
.include "../../sysutils/xfce4-battery-plugin/buildlink3.mk"
.include "../../sysutils/xfce4-cpugraph-plugin/buildlink3.mk"
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "Linux"
.include "../../sysutils/xfce4-diskperf-plugin/buildlink3.mk"
.endif
.include "../../sysutils/xfce4-fsguard-plugin/buildlink3.mk"
.include "../../sysutils/xfce4-genmon-plugin/buildlink3.mk"
.include "../../sysutils/xfce4-netload-plugin/buildlink3.mk"
.include "../../sysutils/xfce4-quicklauncher-plugin/buildlink3.mk"
.include "../../sysutils/xfce4-systemload-plugin/buildlink3.mk"
.include "../../sysutils/xfce4-xkb-plugin/buildlink3.mk"
.include "../../textproc/xfce4-dict-plugin/buildlink3.mk"
.include "../../time/xfce4-datetime-plugin/buildlink3.mk"
.include "../../time/xfce4-timer-plugin/buildlink3.mk"
.include "../../x11/xfce4-clipman-plugin/buildlink3.mk"
.include "../../x11/xfce4-eyes-plugin/buildlink3.mk"
.include "../../x11/xfce4-notes-plugin/buildlink3.mk"
.include "../../x11/xfce4-places-plugin/buildlink3.mk"
.include "../../x11/xfce4-screenshooter-plugin/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
