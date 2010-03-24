# $NetBSD: Makefile,v 1.23 2010/03/24 19:43:27 asau Exp $

DISTNAME=		ntl-5.3.1
PKGREVISION=		2
CATEGORIES=		math devel
MASTER_SITES=		http://www.shoup.net/ntl/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.shoup.net/ntl/
COMMENT=		C++ library for doing number theory

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${DISTNAME}/src
NO_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
MAKE_FILE=		makefile
INSTALLATION_DIRS=	lib

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
