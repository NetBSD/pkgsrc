# $NetBSD: Makefile,v 1.35 2006/02/05 23:08:48 joerg Exp $
#

DISTNAME=	maketool-0.7-src
PKGNAME=	maketool-0.7
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://www.alphalink.com.au/~gnb/maketool/

MAINTAINER=	fredb@NetBSD.org
HOMEPAGE=	http://www.alphalink.com.au/~gnb/maketool/
COMMENT=	Graphical front end to GNU make

BUILD_USES_MSGFMT=	yes
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
