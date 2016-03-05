# $NetBSD: Makefile,v 1.16 2016/03/05 11:27:42 jperkin Exp $

DISTNAME=	mongo-c-driver-1.3.3
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=mongodb/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://github.com/mongodb/mongo-c-driver/
COMMENT=	MongoDB client library written in C
LICENSE=	apache-2.0

GITHUB_RELEASE=	${PKGVERSION_NOREV}

# Requires shm_open()
NOT_FOR_PLATFORM+=	OpenBSD-*-*

.include "options.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

CHECK_PORTABILITY_SKIP+=	src/libbson/configure
CONFIGURE_ARGS+=		--with-libbson=system

PKGCONFIG_OVERRIDE+=	src/libmongoc-1.0.pc.in
PKGCONFIG_OVERRIDE+=	src/libmongoc-ssl-1.0.pc.in

INSTALLATION_DIRS+=	${PKGMANDIR}/man3

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man/mongoc*.3 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man3

BUILDLINK_API_DEPENDS.libbson+=	libbson>=1.3.3
.include "../../devel/libbson/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
