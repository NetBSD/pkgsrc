# $NetBSD: Makefile,v 1.1.1.1 2003/12/29 17:49:22 xtraeme Exp $
#

DISTNAME=		gok-0.8.4
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_GNOME:=desktop/2.4/2.4.1/sources/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME On-Screen Keyboard

DEPENDS+=		gnome2-dirs>=1.2:../../misc/gnome2-dirs

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html
CONFIGURE_ARGS+=	--disable-gtk-doc

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=    ${WRKSRC}/gok-1.0.pc.in

GCONF2_SCHEMAS=		gok.schemas

.include "../../wip/at-spi/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libwnck/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
