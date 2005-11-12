# $NetBSD: Makefile,v 1.1.1.1 2005/11/12 12:35:38 wiz Exp $
#

DISTNAME=		libxml++-2.10.0
PKGNAME=		libxml++2-2.10.0
CATEGORIES=		textproc
MASTER_SITES=		http://ftp.gnome.org/pub/GNOME/sources/libxml++/2.10/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		evaldo@gardenali.biz
HOMEPAGE=		http://libxmlplusplus.sourceforge.net/
COMMENT=		C++ wrapper for the libxml XML parser library

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libxml++-2.6.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config gmake

.include "../../devel/glibmm/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
