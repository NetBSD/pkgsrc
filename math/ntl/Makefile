# $NetBSD: Makefile,v 1.16 2004/10/03 00:12:57 tv Exp $

DISTNAME=		ntl-5.3.1
PKGREVISION=		1
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
