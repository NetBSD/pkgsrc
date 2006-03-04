# $NetBSD: Makefile,v 1.10 2006/03/04 21:30:04 jlam Exp $

DISTNAME=	linpack-20010510
PKGREVISION=	1
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Library of linear algebra Fortran routines

DEPENDS+=	blas-[0-9]*:../../math/blas

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL
USE_LANGUAGES=	fortran
WRKSRC=		${WRKDIR}/linpack

.include "../../mk/bsd.pkg.mk"
