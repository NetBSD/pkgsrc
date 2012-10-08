# $NetBSD: Makefile,v 1.17 2012/10/08 13:45:39 asau Exp $

DISTNAME=	ijs-0.35
CATEGORIES=	print
MASTER_SITES=	http://www.linuxprinting.org/ijs/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.linuxprinting.org/ijs/
COMMENT=	Protocol library for raster page transmission

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

BUILD_TARGET=		libijs.la
MAKE_ENV+=		XCFLAGS=${CFLAGS:M*:Q}
MAKE_ENV+=		IJS_VERSION_INFO="0:0"
PKGCONFIG_OVERRIDE=	ijs.pc.in

INSTALLATION_DIRS=	share/doc/ijs

post-install:
	${INSTALL_DATA} ${WRKSRC}/ijs_spec.pdf ${DESTDIR}${PREFIX}/share/doc/ijs

.include "../../mk/bsd.pkg.mk"
