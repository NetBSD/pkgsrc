# $NetBSD: Makefile,v 1.4 2001/04/13 00:45:04 jtb Exp $

DISTNAME=		ntl-5.0c
CATEGORIES=		math devel
MASTER_SITES=		http://www.shoup.net/ntl/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://www.shoup.net/ntl/
COMMENT=		C++ library for doing number theory

DEPENDS+=		gmp>=3.1.1:../../devel/gmp

WRKSRC=			${WRKDIR}/${DISTNAME}/src

NO_CONFIGURE=		#defined

MAKEFILE=		makefile

EVAL_PREFIX+=		GMP_PREFIX=gmp

.include "../../mk/bsd.pkg.mk"

