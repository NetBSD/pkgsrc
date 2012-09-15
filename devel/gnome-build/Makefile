# $NetBSD: Makefile,v 1.31 2012/09/15 10:04:10 obache Exp $
#

DISTNAME=	gnome-build-2.24.1
PKGREVISION=	17
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-build/2.24/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.anjuta.org/
COMMENT=	GNOME build tools

CONFLICTS+=	anjuta>=2.28

DEPENDS+=	p5-gettext-[0-9]*:../../devel/p5-gettext

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config perl:run intltool msgfmt gmake

PKGCONFIG_OVERRIDE+=	gnome-build-1.0.pc.in

REPLACE_PERL+=		src/backends/libgbf_am/gbf-am-parse.in
REPLACE_PERL+=		src/backends/libgbf_mkfile/gbf-mkfile-parse.in

.include "../../devel/gdl/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
