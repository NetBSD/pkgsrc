# $NetBSD: Makefile,v 1.15 2004/04/14 00:00:19 snj Exp $

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
USE_BUILDLINK3=		yes

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
