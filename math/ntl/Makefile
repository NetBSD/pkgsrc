# $NetBSD: Makefile,v 1.24 2011/12/09 01:21:15 dholland Exp $

DISTNAME=		ntl-5.3.1
PKGREVISION=		2
CATEGORIES=		math devel
MASTER_SITES=		http://www.shoup.net/ntl/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.shoup.net/ntl/
COMMENT=		C++ library for doing number theory

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/${DISTNAME}/src
NO_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
MAKE_FILE=		makefile
INSTALLATION_DIRS=	lib

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
