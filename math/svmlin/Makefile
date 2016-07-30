# $NetBSD: Makefile,v 1.1 2016/07/30 15:13:57 cheusov Exp $

DISTNAME=	svmlin-v1.0
PKGNAME=	${DISTNAME:S/-v/-/}
CATEGORIES=	math
MASTER_SITES=	http://vikas.sindhwani.org/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://vikas.sindhwani.org/
COMMENT=	Fast Linear SVM Solvers for Supervised and Semi-supervised Learning
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c++

post-extract:
	cp "${FILESDIR}/mkc_makefile" "${WRKSRC}"/Makefile

.include "../../devel/mk-configure/mk-c.mk"
.include "../../mk/bsd.pkg.mk"
