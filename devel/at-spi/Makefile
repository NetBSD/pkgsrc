# $NetBSD: Makefile,v 1.5 2004/01/23 21:50:43 jmmv Exp $
#

DISTNAME=		at-spi-1.3.8
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=desktop/2.4/2.4.1/sources/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Assistive Technology Service Provider Interface

DEPENDS+=		gnome2-dirs>=1.2:../../misc/gnome2-dirs

USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_X11=		yes

CONFIGURE_ARGS+=	--disable-gtk-doc

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=    ${WRKSRC}/cspi-1.0.pc.in
PKGCONFIG_OVERRIDE+=    ${WRKSRC}/libspi-1.0.pc.in

.include "../../devel/gail/buildlink2.mk"
.include "../../devel/libbonobo/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
