# $NetBSD: Makefile,v 1.32 2005/06/01 18:02:44 jlam Exp $
#

DISTNAME=	maketool-0.7
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://www.alphalink.com.au/~gnb/maketool/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	fredb@NetBSD.org
HOMEPAGE=	http://www.alphalink.com.au/~gnb/maketool/
COMMENT=	Graphical front end to GNU make

BUILD_USES_MSGFMT=	# defined

USE_PKGLOCALEDIR=	# defined
USE_TOOLS+=		gmake
GNU_CONFIGURE=		# defined
USE_PKGLOCALEDIR=	# defined

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
