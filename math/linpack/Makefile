# $NetBSD: Makefile,v 1.4 2003/03/29 12:41:42 jmmv Exp $

DISTNAME=	linpack-20010510
WRKSRC=		${WRKDIR}/linpack
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	packages@netbsd.org
COMMENT=	Library of linear algebra Fortran routines

DEPENDS+=	blas-[0-9]*:../../math/blas

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL
USE_FORTRAN=	yes

.include "../../mk/bsd.pkg.mk"
