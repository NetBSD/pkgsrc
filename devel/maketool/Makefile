# $NetBSD: Makefile,v 1.5 2000/01/03 23:36:17 fredb Exp $
#

DISTNAME=	maketool-0.5.1
CATEGORIES=	devel
MASTER_SITES=	http://www.alphalink.com.au/~gnb/maketool/
EXTRACT_SUFX=	-src.tgz

MAINTAINER=	fb@enteract.com
HOMEPAGE=	http://www.alphalink.com.au/~gnb/maketool/

BUILD_DEPENDS+=	autoconf:../../devel/autoconf
DEPENDS+=	gettext-0.10.35:../../devel/gettext
DEPENDS+=	gtk+-1.2.*:../../x11/gtk

USE_GMAKE=	yes
USE_X11=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"

pre-configure:
	cd ${WRKSRC}; autoconf

.include "../../mk/bsd.pkg.mk"
