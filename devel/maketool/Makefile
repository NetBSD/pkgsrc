# $NetBSD: Makefile,v 1.12 2001/04/02 20:06:12 wiz Exp $
#

DISTNAME=	maketool-0.6.1
CATEGORIES=	devel
MASTER_SITES=	http://www.alphalink.com.au/~gnb/maketool/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	fb@enteract.com
HOMEPAGE=	http://www.alphalink.com.au/~gnb/maketool/
COMMENT=	Graphical front end to GNU make

BUILD_USES_MSGFMT=	yes
DEPENDS+=	gtk+-1.2.*:../../x11/gtk

USE_GMAKE=	yes
USE_LIBINTL=	yes
USE_X11=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
