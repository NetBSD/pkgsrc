# $NetBSD: Makefile,v 1.50 2026/02/06 10:05:31 wiz Exp $

DISTNAME=	freeDiameter-1.6.0
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=freeDiameter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freediameter.net/trac/
COMMENT=	Open source Diameter protocol implementation
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	c c++
USE_TOOLS+=	bison flex pkg-config
FLEX_REQD+=	2.5.35

CMAKE_CONFIGURE_ARGS+=	-DDISABLE_SCTP:BOOL=ON
CMAKE_CONFIGURE_ARGS+=	-Wno-dev

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

.include "../../devel/cmake/build.mk"
.include "../../devel/libidn2/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
