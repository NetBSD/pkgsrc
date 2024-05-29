# $NetBSD: Makefile,v 1.41 2024/05/29 16:33:57 adam Exp $
#

DISTNAME=	libquvi-0.4.1
PKGREVISION=	34
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=quvi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://quvi.sourceforge.net/
COMMENT=	Library for quvi
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	quvi<=0.2.19

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libquvi.pc.in

BUILDLINK_API_DEPENDS.libquvi-scripts+=		libquvi-scripts>=0.4.0
.include "../../net/libquvi-scripts/buildlink3.mk"
BUILDLINK_API_DEPENDS.curl+=		curl>=7.18.2
.include "../../www/curl/buildlink3.mk"
BUILDLINK_API_DEPENDS.libiconv+=	libiconv>=1.12.0
.include "../../converters/libiconv/buildlink3.mk"
BUILDLINK_API_DEPENDS.lua+=		lua>=5.1
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
