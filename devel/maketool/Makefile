# $NetBSD: Makefile,v 1.28 2004/04/22 04:02:46 snj Exp $
#

DISTNAME=	maketool-0.7
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.alphalink.com.au/~gnb/maketool/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	fredb@NetBSD.org
HOMEPAGE=	http://www.alphalink.com.au/~gnb/maketool/
COMMENT=	Graphical front end to GNU make

BUILD_USES_MSGFMT=	# defined

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	# defined
USE_X11=		# defined
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		# defined
USE_PKGLOCALEDIR=	# defined

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
