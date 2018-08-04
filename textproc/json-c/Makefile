# $NetBSD: Makefile,v 1.13 2018/08/04 09:53:05 adam Exp $

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

# gcc < 4.2 does not have -Wno-error= option.
.if !empty(CC_VERSION:Mgcc-3*) || !empty(CC_VERSION:Mgcc-4.[01]*)
BUILDLINK_TRANSFORM+=	rm:-Werror rm:-Wno-error=deprecated-declarations
.endif

.if !empty(CC_VERSION:Mgcc-[789].*)
CFLAGS+=	-Wimplicit-fallthrough=0
.endif

.include "../../mk/bsd.pkg.mk"
