# $NetBSD: Makefile,v 1.2 2001/11/28 11:46:18 martti Exp $
#

DISTNAME=	yudit-2.4.8
CATEGORIES=	editor
MASTER_SITES=	http://yudit.org/download/

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://yudit.org/
COMMENT=	Unicode Text Editor

USE_BUILDLINK_ONLY=	yes

USE_X11BASE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

.include "../../graphics/freetype-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
