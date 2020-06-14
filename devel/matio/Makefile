# $NetBSD: Makefile,v 1.5 2020/06/14 10:07:48 nia Exp $

DISTNAME=		matio-1.3.3
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=matio/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://sourceforge.net/projects/matio/
COMMENT=		Matlab MAT file I/O library

GNU_CONFIGURE=		yes
# we need a fortran90 compiler for pkgsrc before we can
# enable the fortran part.  The fortran code here is *not*
# compatible with f2c (which is fortran 77).
#USE_LANGUAGES=		c fortran90
#CONFIGURE_ARGS+=	--enable-fortran
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE=	matio.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
