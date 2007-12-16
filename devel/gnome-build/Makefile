# $NetBSD: Makefile,v 1.9 2007/12/16 14:19:00 drochner Exp $
#

DISTNAME=	gnome-build-0.2.0
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-build/0.2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://www.gnome.org/projects/devtools/
COMMENT=	Project management components for GNOME development

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
