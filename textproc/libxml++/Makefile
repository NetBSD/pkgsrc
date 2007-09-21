# $NetBSD: Makefile,v 1.3 2007/09/21 13:04:23 wiz Exp $

DISTNAME=	libxml++-2.18.1
PKGREVISION=	1
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

CONFLICTS+=		libxml++2-[0-9]*

.include "../../devel/glibmm/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
