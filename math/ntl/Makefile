# $NetBSD: Makefile,v 1.1.1.1 2001/01/26 23:46:21 jtb Exp $

DISTNAME=		ntl-5.0c
CATEGORIES=		math devel
MASTER_SITES=		http://www.shoup.net/ntl/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://www.shoup.net/ntl/

DEPENDS+=		gmp-[0-9]*:../../devel/gmp

WRKSRC=			${WRKDIR}/${DISTNAME}/src
NO_CONFIGURE=		YES
MAKEFILE=		makefile
EVAL_PREFIX+=		GMP_PREFIX=gmp
MAKE_ENV+=		"INSTALL_DATA=${INSTALL_DATA}"
MAKE_ENV+=		"INSTALL_DATA_DIR=${INSTALL_DATA_DIR}"

.include "../../mk/bsd.pkg.mk"

