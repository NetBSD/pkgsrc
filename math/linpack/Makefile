# $NetBSD: Makefile,v 1.6 2003/07/17 21:47:44 grant Exp $

DISTNAME=	linpack-20010510
WRKSRC=		${WRKDIR}/linpack
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Library of linear algebra Fortran routines

DEPENDS+=	blas-[0-9]*:../../math/blas

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL
USE_FORTRAN=	yes

.include "../../mk/bsd.pkg.mk"
