# $NetBSD: Makefile,v 1.32 2023/11/14 14:02:48 wiz Exp $

PKGREVISION= 5
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-polkit-${VERSION:R}.1
CATEGORIES=	security

COMMENT=	MATE desktop environment Authentication Agent for PolicyKit
LICENSE=	gnu-lgpl-v2

PKGCONFIG_OVERRIDE+=	polkitgtkmate/polkit-gtk-mate-1.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/${PKGBASE}

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart
CONF_FILES+=	share/examples/mate-polkit/xdg/autostart/polkit-mate-authentication-agent-1.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/polkit-mate-authentication-agent-1.desktop

.include "options.mk"

.include "../../security/polkit/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
