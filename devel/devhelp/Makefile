# $NetBSD: Makefile,v 1.55 2009/09/09 16:47:07 drochner Exp $

DISTNAME=		devhelp-0.23.1
CATEGORIES=		devel x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/devhelp/0.23/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://developer.imendio.com/projects/devhelp
COMMENT=		Documentation viewer based on GNOME2

USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	libdevhelp-1.0.pc.in
GCONF_SCHEMAS=		devhelp.schemas

.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/devhelp
	${INSTALL_DATA} ${WRKSRC}/misc/devhelp.el ${WRKSRC}/misc/devhelp.vim \
		${DESTDIR}${PREFIX}/share/examples/devhelp
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/devhelp
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS COPYING ChangeLog README TODO \
		${DESTDIR}${PREFIX}/share/doc/devhelp

.include "../../mk/bsd.pkg.mk"
