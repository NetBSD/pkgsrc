# $NetBSD: Makefile,v 1.1.1.1 2002/11/02 05:45:30 rh Exp $
#

DISTNAME=		gal2-0-0.0.7
PKGNAME=		${DISTNAME:S/-0-/-/}
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gal2-0/0.0/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME2 Application Libraries

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/gal-2.0.pc.in
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/gal2/html

.include "../../graphics/libgnomecanvas/buildlink2.mk"
.include "../../print/libgnomeprintui/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../textproc/gtk-doc/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
