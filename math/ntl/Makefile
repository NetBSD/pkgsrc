# $NetBSD: Makefile,v 1.9 2003/03/29 12:41:43 jmmv Exp $

DISTNAME=		ntl-5.3.1
WRKSRC=			${WRKDIR}/${DISTNAME}/src
CATEGORIES=		math devel
MASTER_SITES=		http://www.shoup.net/ntl/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.shoup.net/ntl/
COMMENT=		C++ library for doing number theory

DEPENDS+=		gmp>=3.1.1:../../devel/gmp

NO_CONFIGURE=		# defined
USE_LIBTOOL=		yes
MAKEFILE=		makefile

.include "../../devel/gmp/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
