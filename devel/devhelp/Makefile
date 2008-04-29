# $NetBSD: Makefile,v 1.46 2008/04/29 19:27:58 drochner Exp $

DISTNAME=		devhelp-0.19
CATEGORIES=		devel x11
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/devhelp/0.19/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://developer.imendio.com/projects/devhelp
COMMENT=		Documentation viewer based on GNOME2

USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	libdevhelp-1.0.pc.in
GCONF_SCHEMAS=		devhelp.schemas

.include "options.mk"

.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../www/seamonkey/gecko-depends.mk"
.include "../../x11/gtk2/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/devhelp
	${INSTALL_DATA} ${WRKSRC}/misc/devhelp.el ${WRKSRC}/misc/devhelp.vim \
		${PREFIX}/share/examples/devhelp
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/devhelp
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS COPYING ChangeLog README TODO \
		${PREFIX}/share/doc/devhelp

.include "../../mk/bsd.pkg.mk"
