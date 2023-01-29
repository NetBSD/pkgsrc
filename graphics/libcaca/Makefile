# $NetBSD: Makefile,v 1.38 2023/01/29 21:16:39 ryoon Exp $

DISTNAME=	libcaca-0.99.beta19
PKGNAME=	${DISTNAME:S/beta//}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://caca.zoy.org/files/libcaca/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://caca.zoy.org/
COMMENT=	Graphics library that outputs text instead of pixels, in colour
# LICENSE=	wtfpl

TEST_TARGET=		check
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	caca/caca.pc.in

CONFIG_GUESS_OVERRIDE+=	.auto/config.guess
CONFIG_SUB_OVERRIDE+=	.auto/config.sub

.include "options.mk"

CONFIGURE_ARGS+=	--disable-doc

LDFLAGS.Linux+=	-ldl
LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../mk/bsd.pkg.mk"
