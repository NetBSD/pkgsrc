# $NetBSD: Makefile,v 1.7 2014/04/20 00:09:04 ryoon Exp $

DISTNAME=	json-c-0.12
CATEGORIES=	textproc
MASTER_SITES=	https://s3.amazonaws.com/json-c_releases/releases/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/json-c/json-c/wiki
COMMENT=	JSON library in C
LICENSE=	mit

MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	json-c.pc.in

CONFIGURE_ARGS+=	--disable-oldname-compat

# Workaround for https://github.com/json-c/json-c/pull/132
BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-Wno-tautological-compare -Wno-unused-value
.endif

.include "../../mk/bsd.pkg.mk"
