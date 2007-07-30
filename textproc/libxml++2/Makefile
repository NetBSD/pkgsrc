# $NetBSD: Makefile,v 1.5 2007/07/30 02:27:04 obache Exp $

DISTNAME=	libxml++-2.18.1
PKGNAME=	libxml++2-2.18.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libxml++/2.18/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	evaldo@gardenali.biz
HOMEPAGE=	http://libxmlplusplus.sourceforge.net/
COMMENT=	C++ wrapper for the libxml XML parser library

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config gmake
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libxml++-2.6.pc.in
GNU_CONFIGURE=		yes

.include "../../devel/glibmm/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
