# $NetBSD: Makefile,v 1.13 2003/07/17 21:47:50 grant Exp $

DISTNAME=		ntl-5.3.1
WRKSRC=			${WRKDIR}/${DISTNAME}/src
CATEGORIES=		math devel
MASTER_SITES=		http://www.shoup.net/ntl/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.shoup.net/ntl/
COMMENT=		C++ library for doing number theory

NO_CONFIGURE=		# defined
USE_LIBTOOL=		yes
MAKEFILE=		makefile
USE_BUILDLINK2=		yes

.include "../../devel/gmp/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
