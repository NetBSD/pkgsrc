# $NetBSD: Makefile,v 1.33 2005/09/28 13:54:49 rillig Exp $
#

DISTNAME=	maketool-0.7-src
PKGNAME=	maketool-0.7
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://www.alphalink.com.au/~gnb/maketool/

MAINTAINER=	fredb@NetBSD.org
HOMEPAGE=	http://www.alphalink.com.au/~gnb/maketool/
COMMENT=	Graphical front end to GNU make

BUILD_USES_MSGFMT=	yes
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
