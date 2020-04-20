# $NetBSD: Makefile,v 1.16 2020/04/20 07:54:53 adam Exp $

DISTNAME=	yaml-0.2.4
PKGNAME=	lib${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://pyyaml.org/download/libyaml/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pyyaml.org/wiki/LibYAML
COMMENT=	YAML 1.1 parser and emitter written in C
LICENSE=	mit

USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf automake
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	yaml-0.1.pc.in
TEST_TARGET=		check

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

# cmake support is incomplete
#USE_CMAKE=		yes
#CMAKE_ARGS+=		-DBUILD_SHARED_LIBS:BOOL=ON

.include "../../mk/bsd.pkg.mk"
