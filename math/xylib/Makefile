# $NetBSD: Makefile,v 1.1.1.1 2009/12/12 13:58:58 drochner Exp $
#

DISTNAME=	xylib-0.4
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fityk/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fityk.sourceforge.net/
COMMENT=	Library for reading powder diffraction data
#LICENSE=	LICENSE

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
PKG_DESTDIR_SUPPORT= user-destdir

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
