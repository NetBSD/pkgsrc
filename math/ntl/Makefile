# $NetBSD: Makefile,v 1.3 2001/02/17 18:22:31 wiz Exp $

DISTNAME=		ntl-5.0c
CATEGORIES=		math devel
MASTER_SITES=		http://www.shoup.net/ntl/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://www.shoup.net/ntl/
COMMENT=		C++ library for doing number theory

DEPENDS+=		gmp>=3.1.1:../../devel/gmp

WRKSRC=			${WRKDIR}/${DISTNAME}/src
NO_CONFIGURE=		YES
MAKEFILE=		makefile
EVAL_PREFIX+=		GMP_PREFIX=gmp
MAKE_ENV+=		"INSTALL_DATA=${INSTALL_DATA}"
MAKE_ENV+=		"INSTALL_DATA_DIR=${INSTALL_DATA_DIR}"

.include "../../mk/bsd.pkg.mk"

