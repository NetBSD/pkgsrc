# $NetBSD: Makefile,v 1.21 2006/09/09 02:43:10 obache Exp $

DISTNAME=		ntl-5.3.1
PKGREVISION=		1
CATEGORIES=		math devel
MASTER_SITES=		http://www.shoup.net/ntl/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.shoup.net/ntl/
COMMENT=		C++ library for doing number theory

WRKSRC=			${WRKDIR}/${DISTNAME}/src
NO_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
MAKE_FILE=		makefile

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
