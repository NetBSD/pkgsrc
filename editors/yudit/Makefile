# $NetBSD: Makefile,v 1.1.1.1 2001/07/15 16:45:45 wulf Exp $
#

DISTNAME=	yudit-2.4
CATEGORIES=	editor
MASTER_SITES=	http://yudit.org/download/

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://yudit.org/
COMMENT=	Unicode Text Editor

DEPENDS+=	freetype-1.3.1:../../graphics/freetype

USE_X11BASE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-x \
		--with-freetype-includes=${LOCALBASE}/include \
		--with-freetype-libraries=${LOCALBASE}/lib

CPPFLAGS+=	-I${LOCALBASE}/include

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

.include "../../mk/bsd.pkg.mk"
