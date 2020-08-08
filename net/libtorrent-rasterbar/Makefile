# $NetBSD: Makefile,v 1.11 2020/08/08 21:24:25 nia Exp $

DISTNAME=	libtorrent-rasterbar-1.2.8
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=arvidn/}
GITHUB_PROJECT=	libtorrent
GITHUB_RELEASE=	libtorrent-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.libtorrent.org/
COMMENT=	Feature complete C++ bittorrent implementation
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

GCC_REQD+=	6 # c++14

PKGCONFIG_OVERRIDE+=	libtorrent-rasterbar.pc.in

post-install:
	${FIND} ${DESTDIR} -name '*.orig' -exec ${RM} -f {} +

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
