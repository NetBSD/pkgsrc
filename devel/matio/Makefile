# $NetBSD: Makefile,v 1.7 2023/08/31 14:13:42 adam Exp $

DISTNAME=	matio-1.5.23
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=matio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/matio/
COMMENT=	Matlab MAT file I/O library
LICENSE=	2-clause-bsd

# we need a fortran90 compiler for pkgsrc before we can
# enable the fortran part.  The fortran code here is *not*
# compatible with f2c (which is fortran 77).
#USE_LANGUAGES=		c fortran90
#CONFIGURE_ARGS+=	--enable-fortran
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	matio.pc.in

.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
