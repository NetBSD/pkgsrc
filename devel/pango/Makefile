# $NetBSD: Makefile,v 1.22 2003/05/05 14:29:27 jmmv Exp $
#

DISTNAME=		pango-1.2.1
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v2.2/ \
			ftp://ftp.cs.umn.edu/pub/gimp/gtk/v2.2/ \
			${MASTER_SITE_GNOME:=sources/pango/1.2/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.pango.org
COMMENT=		Library for layout and rendering of text

USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes
USE_GMAKE=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes
TEST_TARGET=		check

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/pango.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/pangoft2.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/pangox.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/pangowin32.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/pangoxft.pc.in

PKG_SYSCONFSUBDIR=	pango
EGDIR=			${PREFIX}/share/examples/pango
CONF_FILES=		${EGDIR}/pango.modules ${PKG_SYSCONFDIR}/pango.modules
CONF_FILES+=		${EGDIR}/pangox.aliases ${PKG_SYSCONFDIR}/pangox.aliases

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html
CONFIGURE_ARGS+=	--with-qt=no

.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../fonts/Xft2/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
