# $NetBSD: Makefile,v 1.8 2004/10/03 00:12:56 tv Exp $

DISTNAME=	linpack-20010510
PKGREVISION=	1
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Library of linear algebra Fortran routines

DEPENDS+=	blas-[0-9]*:../../math/blas

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL
USE_FORTRAN=	yes
WRKSRC=		${WRKDIR}/linpack

.include "../../mk/bsd.pkg.mk"
