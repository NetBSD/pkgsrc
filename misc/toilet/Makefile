# $NetBSD: Makefile,v 1.3 2015/03/08 23:29:22 joerg Exp $

DISTNAME=	toilet-0.3
CATEGORIES=	misc
MASTER_SITES=	http://caca.zoy.org/raw-attachment/wiki/toilet/

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://caca.zoy.org/wiki/toilet
COMMENT=	Free replacement for the FIGlet utility
# LICENSE=	wtfpl

USE_TOOLS+=	pkg-config
DEPENDS+=	libcaca>=0.99.18:../../graphics/libcaca

GNU_CONFIGURE=	yes

CONFIG_GUESS_OVERRIDE+=	.auto/config.guess
CONFIG_SUB_OVERRIDE+=	.auto/config.sub

.include "../../graphics/libcaca/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
