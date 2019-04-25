# $NetBSD: Makefile,v 1.14 2019/04/25 07:33:19 maya Exp $

PKGREVISION= 1
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-sensors-applet-${VERSION}
CATEGORIES=	sysutils

COMMENT=	MATE Sensors applets

TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt # for xsltproc

PLIST_VARS+=	netbsd
.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--enable-netbsd
PLIST.netbsd=	yes
.endif

.include "../../devel/glib2/schemas.mk"

.include "../../x11/mate-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
