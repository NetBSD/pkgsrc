# $NetBSD: Makefile,v 1.7 2004/01/20 12:20:05 agc Exp $

DISTNAME=	linpack-20010510
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Library of linear algebra Fortran routines

DEPENDS+=	blas-[0-9]*:../../math/blas

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL
USE_FORTRAN=	yes
WRKSRC=		${WRKDIR}/linpack

.include "../../mk/bsd.pkg.mk"
