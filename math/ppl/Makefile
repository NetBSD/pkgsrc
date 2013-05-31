# $NetBSD: Makefile,v 1.4 2013/05/31 12:41:25 wiz Exp $
#

DISTNAME=	ppl-0.11.2
PKGREVISION=	2
CATEGORIES=	math
#MASTER_SITES=	ftp://gcc.gnu.org/pub/gcc/infrastructure/
MASTER_SITES=	http://www.cs.unipr.it/ppl/Download/ftp/releases/0.11.2/

MAINTAINER=	kuehro@gmx.de
HOMEPAGE=	http://www.cs.unipr.it/ppl/
COMMENT=	The Parma Polyhedra Library. Used by gcc for loop optimization
LICENSE=	gnu-gpl-v3

USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake gmake perl
DEPENDS+=	gsed-[0-9]*:../../textproc/gsed

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes

MAKE_ENV+=	lt_cv_path_SED=${PREFIX}/bin/gsed
CONFIGURE_ARGS+=	--with-gmp-prefix=${PREFIX}
#CONFIGURE_ARGS+=	--enable-interfaces=c,cxx

do-build:
	set -e; cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE}

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
