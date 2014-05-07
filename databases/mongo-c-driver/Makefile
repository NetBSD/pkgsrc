# $NetBSD: Makefile,v 1.1 2014/05/07 15:47:00 fhajny Exp $

DISTNAME=	mongo-c-driver-0.94.2
CATEGORIES=	databases
MASTER_SITES=	https://github.com/mongodb/mongo-c-driver/releases/download/${PKGVERSION_NOREV}/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://github.com/mongodb/mongo-c-driver/
COMMENT=	MongoDB client library written in C
LICENSE=	apache-2.0

BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

# Requires shm_open()
NOT_FOR_PLATFORM+=	NetBSD-*-* OpenBSD-*-*

.include "options.mk"

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

CHECK_PORTABILITY_SKIP+=	src/libbson/configure
CONFIGURE_ARGS+=		--with-libbson=system

PKGCONFIG_OVERRIDE+=	src/libmongoc-1.0.pc.in
PKGCONFIG_OVERRIDE+=	src/libmongoc-ssl-1.0.pc.in

.include "../../devel/libbson/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
