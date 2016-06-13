# $NetBSD: Makefile,v 1.2 2016/06/13 23:28:36 youri Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-polkit-${MATE_VERSION}
PKGREVISION=	1
CATEGORIES=	security

COMMENT=	MATE desktop environment Authentication Agent for PolicyKit

PKGCONFIG_OVERRIDE+=	polkitgtkmate/polkit-gtk-mate-1.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/${PKGBASE}

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart
CONF_FILES+=	share/examples/mate-polkit/xdg/autostart/polkit-mate-authentication-agent-1.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/polkit-mate-authentication-agent-1.desktop

.include "options.mk"

.include "../../security/polkit/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
