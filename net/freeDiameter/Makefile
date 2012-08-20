# $NetBSD: Makefile,v 1.1 2012/08/20 12:17:20 wiz Exp $
#

DISTNAME=	1.1.2
PKGNAME=	freeDiameter-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://www.freediameter.net/hg/freeDiameter/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freediameter.net/trac/
COMMENT=	Open source Diameter protocol implementation
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

DIST_SUBDIR=	freeDiameter

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_CMAKE=	yes
CMAKE_ARGS+=    -DDISABLE_SCTP:BOOL=ON
USE_LANGUAGES=	c c++
USE_TOOLS+=	bison pkg-config

.include "options.mk"

INSTALLATION_DIRS=	share/examples/freeDiameter/single_host

post-install:
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.* \
		${DESTDIR}${PREFIX}/share/examples/freeDiameter
	cd ${WRKSRC}/doc/single_host && ${INSTALL_DATA} *.* \
		${DESTDIR}${PREFIX}/share/examples/freeDiameter/single_host

.include "../../devel/libidn/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
