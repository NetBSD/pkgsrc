# $NetBSD: Makefile,v 1.3 2010/07/31 19:14:08 dholland Exp $
#

DISTNAME=		gromacs-4.0.7
PKGREVISION=		2
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.gromacs.org/pub/gromacs/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gromacs.org/
COMMENT=		Molecular dynamics package
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

# Official recommendation is not to use the gcc 4.1.x set of compilers.

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-double --program-suffix=
CONFIGURE_ARGS+=	--with-gsl

.include "options.mk"

USE_TOOLS+=		perl:run
REPLACE_PERL=		scripts/demux.pl scripts/xplor2gmx.pl

.include "../../math/fftw/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"	# optional
.include "../../textproc/libxml2/buildlink3.mk"	# optional
.include "../../mk/bsd.pkg.mk"
