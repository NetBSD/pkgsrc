# $NetBSD: Makefile,v 1.22 2020/11/05 09:07:31 ryoon Exp $
#

DISTNAME=		gromacs-4.5.5
PKGREVISION=		11
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.gromacs.org/pub/gromacs/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gromacs.org/
COMMENT=		Molecular dynamics package
LICENSE=		gnu-gpl-v2

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

CHECK_INTERPRETER_SKIP+=	share/gromacs/tutor/gmxdemo/demo

.include "../../mk/bsd.prefs.mk"

.if $(MACHINE_ARCH) == "i386"
CFLAGS+=	-msse -msse2
.endif

.include "../../math/fftw/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"	# optional
.include "../../textproc/libxml2/buildlink3.mk"	# optional
.include "../../mk/bsd.pkg.mk"
