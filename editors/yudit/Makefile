# $NetBSD: Makefile,v 1.12 2004/04/11 08:33:10 snj Exp $
#

DISTNAME=	yudit-2.7.6
CATEGORIES=	editors
MASTER_SITES=	http://yudit.org/download/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://yudit.org/
COMMENT=	Unicode Text Editor

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_LANGUAGES=	c c++
USE_X11=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-x

.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
