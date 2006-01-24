# $NetBSD: Makefile,v 1.22 2006/01/24 07:32:22 wiz Exp $

.include "Makefile.common"

XFCE4_VERSION=	4.2.3.2

DISTNAME=	xfce4-${XFCE4_VERSION}
DISTFILES=	# empty
PKGREVISION=	1
CATEGORIES=	meta-pkgs
COMMENT=	Xfce

NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes
WRKSRC=		${WRKDIR}

do-install:
	@${DO_NADA}

.include "../../audio/xfce4-mixer/buildlink3.mk"
.include "../../graphics/xfce4-icon-theme/buildlink3.mk"
.include "../../graphics/xfce4-iconbox/buildlink3.mk"
.include "../../print/xfce4-print/buildlink3.mk"
.include "../../sysutils/xfce4-appfinder/buildlink3.mk"
.include "../../sysutils/xfce4-fm/buildlink3.mk"
.include "../../sysutils/xfce4-systray/buildlink3.mk"
.include "../../time/xfce4-calendar/buildlink3.mk"
.include "../../wm/xfce4-wm-themes/buildlink3.mk"
.include "../../wm/xfce4-wm/buildlink3.mk"
.include "../../x11/xfce4-desktop/buildlink3.mk"
.include "../../x11/xfce4-gtk2-engine/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../x11/xfce4-session/buildlink3.mk"
.include "../../x11/xfce4-toys/buildlink3.mk"
.include "../../x11/xfce4-trigger-launcher/buildlink3.mk"
.include "../../x11/xfce4-utils/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
