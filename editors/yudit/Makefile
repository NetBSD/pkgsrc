# $NetBSD: Makefile,v 1.11 2004/02/05 10:09:03 grant Exp $
#

DISTNAME=	yudit-2.7.6
CATEGORIES=	editors
MASTER_SITES=	http://yudit.org/download/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://yudit.org/
COMMENT=	Unicode Text Editor

USE_BUILDLINK2=	yes
USE_GNU_TOOLS+=	make
USE_LANGUAGES=	c c++
USE_X11=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-x

.include "../../graphics/freetype-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
