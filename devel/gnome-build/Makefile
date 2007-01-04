# $NetBSD: Makefile,v 1.1.1.1 2007/01/04 02:51:02 rillig Exp $
#

DISTNAME=	gnome-build-0.1.3
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-build/0.1/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://www.gnome.org/projects/devtools/
COMMENT=	Project management components for GNOME development

BL3_DEPENDS+=	devel/gal
BL3_DEPENDS+=	devel/gdl
BL3_DEPENDS+=	devel/libbonobo
BL3_DEPENDS+=	devel/libgnome
BL3_DEPENDS+=	devel/libgnomeui
BL3_DEPENDS+=	devel/oaf
BL3_DEPENDS+=	devel/pango
BL3_DEPENDS+=	x11/gtk2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config perl:run

PKGCONFIG_OVERRIDE+=	gnome-build-1.0.pc.in

REPLACE_PERL+=		src/backends/libgbf_am/gbf-am-parse.in
REPLACE_PERL+=		src/backends/libgbf_mkfile/gbf-mkfile-parse.in

.for d in ${BL3_DEPENDS}
.  include "../../${d}/buildlink3.mk"
.endfor
.include "../../mk/bsd.pkg.mk"
