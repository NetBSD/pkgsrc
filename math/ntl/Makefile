# $NetBSD: Makefile,v 1.10 2003/04/30 00:14:00 jtb Exp $

DISTNAME=		ntl-5.3.1
WRKSRC=			${WRKDIR}/${DISTNAME}/src
CATEGORIES=		math devel
MASTER_SITES=		http://www.shoup.net/ntl/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.shoup.net/ntl/
COMMENT=		C++ library for doing number theory

NO_CONFIGURE=		# defined
USE_LIBTOOL=		yes
MAKEFILE=		makefile

.include "../../devel/gmp/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
