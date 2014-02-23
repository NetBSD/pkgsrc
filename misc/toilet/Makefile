# $NetBSD: Makefile,v 1.1 2014/02/23 00:40:04 schmonz Exp $

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

.include "../../graphics/libcaca/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
