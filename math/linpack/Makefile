# $NetBSD: Makefile,v 1.9 2005/01/12 15:32:01 jlam Exp $

DISTNAME=	linpack-20010510
PKGREVISION=	1
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Library of linear algebra Fortran routines

DEPENDS+=	blas-[0-9]*:../../math/blas

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL
USE_LANGUAGES=	fortran
WRKSRC=		${WRKDIR}/linpack

.include "../../mk/bsd.pkg.mk"
