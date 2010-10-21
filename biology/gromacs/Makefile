# $NetBSD: Makefile,v 1.5 2010/10/21 12:03:57 asau Exp $
#

DISTNAME=		gromacs-4.5.1
PKGNAME=		$(DISTNAME:=.1)
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.gromacs.org/pub/gromacs/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gromacs.org/
COMMENT=		Molecular dynamics package
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

# GROMACS team released another version a day after:
# 4.5.1-20100902-2d7e855 vs.
# 4.5.1-20100903-d982058
# call it 4.5.1.1
DIST_SUBDIR=		gromacs-4.5.1.1

# Official recommendation is not to use the gcc 4.1.x set of compilers.

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-double --program-suffix=
CONFIGURE_ARGS+=	--with-gsl
CONFIGURE_ARGS+=	--disable-gcc41-check

.include "options.mk"

USE_TOOLS+=		perl:run
REPLACE_PERL=		scripts/demux.pl scripts/xplor2gmx.pl

.include "../../math/fftw/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"	# optional
.include "../../textproc/libxml2/buildlink3.mk"	# optional
.include "../../mk/bsd.pkg.mk"
