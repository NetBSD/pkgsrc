# $NetBSD: Makefile,v 1.14 2012/09/11 23:04:23 asau Exp $

DISTNAME=	linpack-20010510
PKGREVISION=	2
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Library of linear algebra Fortran routines

DEPENDS+=	blas-[0-9]*:../../math/blas

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL
USE_LANGUAGES=	fortran77
WRKSRC=		${WRKDIR}/linpack
INSTALLATION_DIRS=	lib

.include "../../mk/bsd.pkg.mk"
