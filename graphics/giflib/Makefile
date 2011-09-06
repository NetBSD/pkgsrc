# $NetBSD: Makefile,v 1.43 2011/09/06 18:45:46 drochner Exp $
#

DISTNAME=	giflib-4.1.6
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=giflib/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://giflib.sourceforge.net/
COMMENT=	GIF image format library
LICENSE=	mit

CONFLICTS+=	libungif-[0-9]*
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

BUILD_DIRS=	lib
INSTALL_DIRS=	lib

.include "../../mk/bsd.pkg.mk"
