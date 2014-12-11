# $NetBSD: Makefile,v 1.8 2014/12/11 22:12:33 joerg Exp $
#

CLISP_MODULE=	pari

PKGNAME=	clisp-${CLISP_MODULE}-${CLISP_VERSION}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clisp/}

MAINTAINER=	hans@NetBSD.org
HOMEPAGE=	http://clisp.cons.org/
COMMENT=	CLISP pari module

MAKE_JOBS_SAFE=	no

.include "../../lang/clisp/module.mk"
.include "../../math/pari/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"

ac_cv_libpari_libs=     -L${BUILDLINK_PREFIX.pari}/lib -l${PARI_LIB}
.if ${PARI_LIB} == "pari-gmp"
ac_cv_libpari_libs+=    -L${BUILDLINK_PREFIX.gmp}/lib -lgmp
.endif

CONFIGURE_ENV+=	"ac_cv_libpari_libs=${ac_cv_libpari_libs} ${COMPILER_RPATH_FLAG}${LOCALBASE}/lib"

.include "../../mk/bsd.pkg.mk"
