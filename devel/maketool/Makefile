# $NetBSD: Makefile,v 1.16 2001/07/13 14:41:19 fredb Exp $
#

DISTNAME=	maketool-0.6.1
CATEGORIES=	devel
MASTER_SITES=	http://www.alphalink.com.au/~gnb/maketool/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	fredb@netbsd.org
HOMEPAGE=	http://www.alphalink.com.au/~gnb/maketool/
COMMENT=	Graphical front end to GNU make

USE_BUILDLINK_ONLY=	YES
BUILD_USES_MSGFMT=	YES

USE_GMAKE=	yes
USE_X11=	yes

GNU_CONFIGURE=	yes

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
