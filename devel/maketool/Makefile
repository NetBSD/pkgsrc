# $NetBSD: Makefile,v 1.21 2002/09/21 10:57:08 jlam Exp $
#

DISTNAME=	maketool-0.7
CATEGORIES=	devel
MASTER_SITES=	http://www.alphalink.com.au/~gnb/maketool/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	fredb@netbsd.org
HOMEPAGE=	http://www.alphalink.com.au/~gnb/maketool/
COMMENT=	Graphical front end to GNU make

BUILD_USES_MSGFMT=	# defined

USE_BUILDLINK2=		# defined
USE_X11=		# defined
USE_GMAKE=		# defined
GNU_CONFIGURE=		# defined

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
