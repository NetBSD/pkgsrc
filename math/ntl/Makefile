# $NetBSD: Makefile,v 1.6 2001/05/03 22:16:51 jtb Exp $

DISTNAME=		ntl-5.0c
CATEGORIES=		math devel
MASTER_SITES=		http://www.shoup.net/ntl/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.shoup.net/ntl/
COMMENT=		C++ library for doing number theory

DEPENDS+=		gmp>=3.1.1:../../devel/gmp

WRKSRC=			${WRKDIR}/${DISTNAME}/src

NO_CONFIGURE=		#defined

MAKEFILE=		makefile

GMP_PREFIX_DEFAULT=	${LOCALBASE}
EVAL_PREFIX+=		GMP_PREFIX=gmp

.include "../../mk/bsd.pkg.mk"

