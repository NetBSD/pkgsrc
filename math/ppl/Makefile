# $NetBSD: Makefile,v 1.16 2020/05/31 16:59:03 rillig Exp $

DISTNAME=	ppl-1.2
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.cs.unipr.it/pub/ppl/releases/1.2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cs.unipr.it/ppl/
COMMENT=	The Parma Polyhedra Library
LICENSE=	gnu-gpl-v3

USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake gmake perl
DEPENDS+=	gsed-[0-9]*:../../textproc/gsed

USE_LANGUAGES=	c gnu++03
GNU_CONFIGURE=	yes

MAKE_ENV+=		lt_cv_path_SED=${PREFIX}/bin/gsed
#CONFIGURE_ARGS+=	--enable-interfaces=c,cxx

do-build:
	set -e; cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE}

TEST_TARGET=	check

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
