# $NetBSD: Makefile,v 1.27 2004/04/01 19:09:07 jmmv Exp $
#

DISTNAME=		gnome-utils-2.6.0
CATEGORIES=		misc gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-utils/2.6/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Set of useful GNOME2 utilities and applications

BUILD_USES_MSGFMT=	yes
DEPENDS+=		xdg-dirs>=1.1:../../misc/xdg-dirs

USE_PERL5=		build
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

GCONF2_SCHEMAS+=	gdict.schemas
GCONF2_SCHEMAS+=	gnome-search-tool.schemas
GCONF2_SCHEMAS+=	logview.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/GConf2-ui/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
