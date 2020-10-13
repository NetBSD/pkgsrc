# $NetBSD: Makefile,v 1.16 2020/10/13 12:11:07 bacon Exp $

DISTNAME=	linpack-20010510
PKGREVISION=	3
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Library of linear algebra Fortran routines

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
USE_LANGUAGES=		fortran77
WRKSRC=			${WRKDIR}/linpack
INSTALLATION_DIRS=	lib

.include "../../mk/blas.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
