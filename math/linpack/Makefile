# $NetBSD: Makefile,v 1.5 2003/06/02 01:18:30 jschauma Exp $

DISTNAME=	linpack-20010510
WRKSRC=		${WRKDIR}/linpack
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	Library of linear algebra Fortran routines

DEPENDS+=	blas-[0-9]*:../../math/blas

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL
USE_FORTRAN=	yes

.include "../../mk/bsd.pkg.mk"
