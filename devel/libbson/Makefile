# $NetBSD: Makefile,v 1.25 2017/08/17 17:00:47 fhajny Exp $

DISTNAME=	libbson-1.7.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mongodb/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	https://github.com/mongodb/libbson/
COMMENT=	BSON utility library
LICENSE=	apache-2.0

GITHUB_RELEASE=	${PKGVERSION_NOREV}

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	src/libbson-1.0.pc.in

INSTALLATION_DIRS+=	${PKGMANDIR}/man3

TEST_TARGET=	test

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man/bson_*.3 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man3

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
