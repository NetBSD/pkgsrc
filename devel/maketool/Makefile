# $NetBSD: Makefile,v 1.14 2001/06/26 14:01:53 zuntum Exp $
#

DISTNAME=	maketool-0.6.1
CATEGORIES=	devel
MASTER_SITES=	http://www.alphalink.com.au/~gnb/maketool/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	fb@enteract.com
HOMEPAGE=	http://www.alphalink.com.au/~gnb/maketool/
COMMENT=	Graphical front end to GNU make

USE_BUILDLINK_ONLY=	YES
USE_CONFIG_WRAPPER=	YES
BUILD_USES_MSGFMT=	YES

USE_GMAKE=	yes
USE_LIBINTL=	yes
USE_X11=	yes

GNU_CONFIGURE=	yes

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
