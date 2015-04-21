# $NetBSD: Makefile,v 1.8 2015/04/21 07:59:39 fhajny Exp $

DISTNAME=	mongo-c-driver-1.1.4
CATEGORIES=	databases
MASTER_SITES=	https://github.com/mongodb/mongo-c-driver/releases/download/${PKGVERSION_NOREV}/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://github.com/mongodb/mongo-c-driver/
COMMENT=	MongoDB client library written in C
LICENSE=	apache-2.0

BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

# Requires shm_open()
NOT_FOR_PLATFORM+=	OpenBSD-*-*

.include "options.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

CHECK_PORTABILITY_SKIP+=	src/libbson/configure
CONFIGURE_ARGS+=		--with-libbson=system
CONFIGURE_ARGS+=		--enable-man-pages=yes

PKGCONFIG_OVERRIDE+=	src/libmongoc-1.0.pc.in
PKGCONFIG_OVERRIDE+=	src/libmongoc-ssl-1.0.pc.in

BUILDLINK_API_DEPENDS.libbson+=	libbson>=1.1.4
.include "../../devel/libbson/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
