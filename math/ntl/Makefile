# $NetBSD: Makefile,v 1.19 2006/03/04 21:30:04 jlam Exp $

DISTNAME=		ntl-5.3.1
PKGREVISION=		1
CATEGORIES=		math devel
MASTER_SITES=		http://www.shoup.net/ntl/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.shoup.net/ntl/
COMMENT=		C++ library for doing number theory

WRKSRC=			${WRKDIR}/${DISTNAME}/src
NO_CONFIGURE=		yes
USE_LIBTOOL=		yes
MAKEFILE=		makefile

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
