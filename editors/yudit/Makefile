# $NetBSD: Makefile,v 1.15 2005/05/22 20:07:57 jlam Exp $
#

DISTNAME=	yudit-2.7.6
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://yudit.org/download/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://yudit.org/
COMMENT=	Unicode Text Editor

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
USE_X11=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-x

.include "../../graphics/freetype-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
