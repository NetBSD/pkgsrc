# $NetBSD: Makefile,v 1.3 2011/11/25 23:47:16 hans Exp $
#

CLISP_MODULE=	pari

PKGNAME=	clisp-$(CLISP_MODULE)-$(CLISP_VERSION)
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	$(MASTER_SITE_SOURCEFORGE:=clisp/)

MAINTAINER=	hans@netbsd.org
HOMEPAGE=	http://clisp.cons.org/
COMMENT=	CLISP pari module

MAKE_JOBS_SAFE=	no

.include "../../lang/clisp/module.mk"
.include "../../math/pari/buildlink3.mk"

ac_cv_libpari_libs=     -l${PARI_LIB}
.if ${PARI_LIB} == "pari-gmp"
ac_cv_libpari_libs+=    -lgmp
.endif

CONFIGURE_ENV+=	"ac_cv_libpari_libs=${ac_cv_libpari_libs} -R${LOCALBASE}/lib"

.include "../../mk/bsd.pkg.mk"
