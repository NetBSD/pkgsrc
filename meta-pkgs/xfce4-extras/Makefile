# $NetBSD: Makefile,v 1.23 2007/04/17 18:42:24 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-extras-${XFCE4_VERSION}
DISTFILES=	# empty
#PKGREVISION=	1
CATEGORIES=	meta-pkgs
COMMENT=	Xfce extras

NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes
WRKSRC=		${WRKDIR}

do-install:
	@${DO_NADA}

# Xfce
.include "../../meta-pkgs/xfce4/buildlink3.mk"

#
# Do you want to have more plugins? See http://goodies.xfce.org/releases/
# for all available plugins...
#

# Additional plugins etc.
.include "../../audio/xfce4-xmms-plugin/buildlink3.mk"
.include "../../misc/xfce4-weather-plugin/buildlink3.mk"
.include "../../net/xfce4-wavelan-plugin/buildlink3.mk"
.include "../../sysutils/xfce4-cpugraph-plugin/buildlink3.mk"
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "Linux"
.include "../../sysutils/xfce4-diskperf-plugin/buildlink3.mk"
.endif
.include "../../sysutils/xfce4-fsguard-plugin/buildlink3.mk"
.include "../../sysutils/xfce4-netload-plugin/buildlink3.mk"
.include "../../sysutils/xfce4-quicklauncher-plugin/buildlink3.mk"
.include "../../sysutils/xfce4-systemload-plugin/buildlink3.mk"
.include "../../sysutils/xfce4-xkb-plugin/buildlink3.mk"
.include "../../time/xfce4-datetime-plugin/buildlink3.mk"
.include "../../x11/xfce4-clipman-plugin/buildlink3.mk"
.include "../../x11/xfce4-notes-plugin/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
