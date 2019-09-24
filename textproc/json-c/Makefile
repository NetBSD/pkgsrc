# $NetBSD: Makefile,v 1.14 2019/09/24 16:08:29 kamil Exp $

DISTNAME=	json-c-0.13.1
CATEGORIES=	textproc
MASTER_SITES=	https://s3.amazonaws.com/json-c_releases/releases/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/json-c/json-c/wiki
COMMENT=	JSON library in C
LICENSE=	mit

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	json-c.pc.in
TEST_TARGET=		check

.include "../../mk/compiler.mk"

BUILDLINK_TRANSFORM+=	rm:-Werror # -Werror,-Wimplicit-int-float-conversion fixed in https://github.com/json-c/json-c/commit/d0b87ee87b282e9b91a1af924050e217b0b2ae8b.patch

# gcc < 4.2 does not have -Wno-error= option.
.if !empty(CC_VERSION:Mgcc-3*) || !empty(CC_VERSION:Mgcc-4.[01]*)
BUILDLINK_TRANSFORM+=	rm:-Werror rm:-Wno-error=deprecated-declarations
.endif

.if !empty(CC_VERSION:Mgcc-[789].*)
CFLAGS+=	-Wimplicit-fallthrough=0
.endif

.include "../../mk/bsd.pkg.mk"
