# $NetBSD: Makefile,v 1.19 2001/10/24 22:10:53 jlam Exp $
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
GNU_CONFIGURE=	yes

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
