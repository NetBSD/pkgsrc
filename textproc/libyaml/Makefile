# $NetBSD: Makefile,v 1.13 2019/04/04 23:54:08 kamil Exp $

DIST_SUBDIR=	yaml # Remove for next version

DISTNAME=	yaml-0.2.2
PKGNAME=	lib${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://pyyaml.org/download/libyaml/

PKGREVISION=	1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pyyaml.org/wiki/LibYAML
COMMENT=	YAML 1.1 parser and emitter written in C
LICENSE=	mit

USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf automake
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	yaml-0.1.pc.in
TEST_TARGET=		check

#WRKSRC=		${WRKDIR}/lib${DISTNAME}

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

# cmake support is incomplete
#USE_CMAKE=		yes
#CMAKE_ARGS+=		-DBUILD_SHARED_LIBS:BOOL=ON
#post-install:
#	${RM} -rf ${DESTDIR}${PREFIX}/cmake

.include "../../mk/bsd.pkg.mk"
