# $NetBSD: Makefile,v 1.40 2023/11/08 13:21:06 wiz Exp $

DISTNAME=	libxml++-2.40.1
PKGREVISION=	15
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libxml++/2.40/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	evaldo@gardenali.biz
HOMEPAGE=	http://libxmlplusplus.sourceforge.net/
COMMENT=	C++ wrapper for the libxml XML parser library (2.6 API)
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config gmake perl
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libxml++-2.6.pc.in
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	MMDOCTOOLDIR=${PREFIX}/share/glibmm-2.4/doctool

CONFLICTS+=		libxml++2-[0-9]*

.include "../../devel/glibmm/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
