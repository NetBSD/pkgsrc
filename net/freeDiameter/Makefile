# $NetBSD: Makefile,v 1.39 2023/11/08 13:20:23 wiz Exp $

DISTNAME=	1.5.0
PKGNAME=	freeDiameter-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	net
MASTER_SITES=	http://www.freediameter.net/hg/freeDiameter/archive/
DIST_SUBDIR=	freeDiameter

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freediameter.net/trac/
COMMENT=	Open source Diameter protocol implementation
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_CMAKE=	yes
CMAKE_ARGS+=	-DDISABLE_SCTP:BOOL=ON
USE_LANGUAGES=	c c++
USE_TOOLS+=	bison flex pkg-config
FLEX_REQD=	2.5.35

LDFLAGS.SunOS+=	-lsocket -lnsl

# needs libraries installed
#TEST_TARGET=	test

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
