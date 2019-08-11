# $NetBSD: Makefile,v 1.34 2019/08/11 13:21:44 wiz Exp $

DISTNAME=		ntl-6.0.0
PKGREVISION=		6
CATEGORIES=		math devel
MASTER_SITES=		http://www.shoup.net/ntl/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.shoup.net/ntl/
COMMENT=		C++ library for doing number theory

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
