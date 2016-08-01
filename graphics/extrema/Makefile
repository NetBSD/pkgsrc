# $NetBSD: Makefile,v 1.27 2016/08/01 04:03:48 mef Exp $
#

DISTNAME=	extrema-4.4.5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=extrema/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://exsitewebware.com/extrema/
COMMENT=	Visualization and data analysis tool
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
CONFIGURE_ARGS+=	--with-wxGTK

.include "../../mk/wxGTK.mk"
.include "../../mk/bsd.pkg.mk"
