# $NetBSD: Makefile,v 1.3 2001/05/10 23:51:06 jtb Exp $

DISTNAME=	linpack-20010510
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	packages@netbsd.org
COMMENT=	Library of linear algebra Fortran routines

DEPENDS+=	blas-[0-9]*:../../math/blas

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL
WRKSRC=		${WRKDIR}/linpack
USE_FORTRAN=	yes

.include "../../mk/bsd.pkg.mk"
