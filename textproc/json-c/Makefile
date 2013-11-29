# $NetBSD: Makefile,v 1.5 2013/11/29 17:45:18 wiz Exp $

DISTNAME=	json-c-0.11
PKGREVISION=	1
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

PKGCONFIG_OVERRIDE+=	json.pc.in
PKGCONFIG_OVERRIDE+=	json-c.pc.in

CONFIGURE_ARGS+=	--disable-oldname-compat

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-Wno-tautological-compare -Wno-unused-value
.endif

.include "../../mk/bsd.pkg.mk"
