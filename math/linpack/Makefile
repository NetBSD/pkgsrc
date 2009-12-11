# $NetBSD: Makefile,v 1.12 2009/12/11 01:34:38 asau Exp $

DISTNAME=	linpack-20010510
PKGREVISION=	2
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Library of linear algebra Fortran routines

DEPENDS+=	blas-[0-9]*:../../math/blas

PKG_DESTDIR_SUPPORT=	user-destdir

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL
USE_LANGUAGES=	fortran
WRKSRC=		${WRKDIR}/linpack
INSTALLATION_DIRS=	lib

.include "../../mk/bsd.pkg.mk"
