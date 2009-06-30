# $NetBSD: Makefile,v 1.28 2009/06/30 00:07:13 joerg Exp $

DISTNAME=	netcdf-3.6.0-p1
PKGNAME=	netcdf-3.6.0p1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://www.gfd-dennou.org/arch/netcdf/unidata-mirror/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.unidata.ucar.edu/software/netcdf/index.html
COMMENT=	Library for array-oriented data access

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${DISTNAME}/src
USE_LANGUAGES=		c c++ fortran
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
MAKE_FLAGS+=		MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR} \
			exec_prefix=${DESTDIR}${PREFIX}
CPPFLAGS+=		-Df2cFortran -Dunix
MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.pkg.mk"
