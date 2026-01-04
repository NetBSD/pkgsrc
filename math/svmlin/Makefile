# $NetBSD: Makefile,v 1.3 2026/01/04 11:36:14 wiz Exp $

DISTNAME=	svmlin-v1.0
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	math
MASTER_SITES=	http://vikas.sindhwani.org/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://vikas.sindhwani.org/
COMMENT=	Fast Linear SVM Solvers for Supervised and Semi-supervised Learning
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c++
# ssl.cpp:804:24: warning: ISO C++17 does not allow 'register' storage class specifier [-Wregister]
FORCE_CXX_STD=	c++11

post-extract:
	cp "${FILESDIR}/mkc_makefile" "${WRKSRC}"/Makefile

.include "../../devel/mk-configure/mk-c.mk"
.include "../../mk/bsd.pkg.mk"
