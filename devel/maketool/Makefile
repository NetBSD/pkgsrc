# $NetBSD: Makefile,v 1.9 2000/12/31 14:00:09 wiz Exp $
#

DISTNAME=	maketool-0.6.1
CATEGORIES=	devel
MASTER_SITES=	http://www.alphalink.com.au/~gnb/maketool/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	fb@enteract.com
HOMEPAGE=	http://www.alphalink.com.au/~gnb/maketool/

BUILD_DEPENDS+=	msgfmt:../../devel/gettext
DEPENDS+=	gtk+-1.2.*:../../x11/gtk

USE_GMAKE=	yes
USE_LIBINTL=	yes
USE_X11=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
