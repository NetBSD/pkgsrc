# $NetBSD: Makefile,v 1.7 2003/02/23 03:19:54 salo Exp $
#

DISTNAME=	yudit-2.7.2
CATEGORIES=	editors
MASTER_SITES=	http://yudit.org/download/

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://yudit.org/
COMMENT=	Unicode Text Editor

USE_BUILDLINK2=	yes
USE_GMAKE=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-x

.include "../../graphics/freetype-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
