# $NetBSD: Makefile,v 1.41 2011/01/18 11:57:53 drochner Exp $
#

DISTNAME=	giflib-4.1.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=giflib/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://giflib.sourceforge.net/
COMMENT=	GIF image format library
#LICENSE=	# TODO: (see mk/license.mk)

CONFLICTS+=	libungif-[0-9]*
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../mk/bsd.pkg.mk"
