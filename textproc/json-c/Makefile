# $NetBSD: Makefile,v 1.9 2014/05/10 04:09:41 pho Exp $

DISTNAME=	json-c-0.12
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

PKGCONFIG_OVERRIDE+=	json-c.pc.in

CONFIGURE_ARGS+=	--disable-oldname-compat

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-Wno-tautological-compare -Wno-unused-value
.endif

# gcc < 4.2 does not have -Wno-error= option.
.if !empty(CC_VERSION:Mgcc-3*) || !empty(CC_VERSION:Mgcc-4.[01]*)
BUILDLINK_TRANSFORM+=	rm:-Werror rm:-Wno-error=deprecated-declarations
.endif

.include "../../mk/bsd.pkg.mk"
