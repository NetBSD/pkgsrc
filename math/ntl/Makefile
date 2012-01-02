# $NetBSD: Makefile,v 1.25 2012/01/02 23:42:27 dholland Exp $

DISTNAME=		ntl-5.5.2
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
USE_TOOLS+=		perl
USE_LIBTOOL=		yes
MAKE_FILE=		makefile
INSTALLATION_DIRS=	lib

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
