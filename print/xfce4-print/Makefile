# $NetBSD: Makefile,v 1.38 2012/09/15 10:06:12 obache Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

PKGNAME=	xfce4-print-${XFCE4_VERSION}
DISTNAME=	xfprint-${XFCE4_VERSION}
PKGREVISION=	12
CATEGORIES=	print
COMMENT=	Xfce print dialog

PKGCONFIG_OVERRIDE+=	libxfprint/xfprint-1.0.pc.in

CONFIGURE_ARGS+=	--with-printcap=/etc/printcap

MAKE_DIRS+=	${PREFIX}/include/xfce4 ${PREFIX}/lib/xfce4
MAKE_DIRS+=	${PREFIX}/share/xfce4 ${PREFIX}/share/xfce4/doc
MAKE_DIRS+=	${PREFIX}/share/xfce4/doc/C ${PREFIX}/share/xfce4/doc/C/images
MAKE_DIRS+=	${PREFIX}/share/xfce4/doc/fr ${PREFIX}/share/xfce4/doc/fr/images

.include "options.mk"

.include "../../devel/xfconf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../print/a2ps/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
