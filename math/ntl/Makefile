# $NetBSD: Makefile,v 1.14 2004/01/20 12:20:05 agc Exp $

DISTNAME=		ntl-5.3.1
CATEGORIES=		math devel
MASTER_SITES=		http://www.shoup.net/ntl/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.shoup.net/ntl/
COMMENT=		C++ library for doing number theory

WRKSRC=			${WRKDIR}/${DISTNAME}/src
NO_CONFIGURE=		# defined
USE_LIBTOOL=		yes
MAKEFILE=		makefile
USE_BUILDLINK2=		yes

.include "../../devel/gmp/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
