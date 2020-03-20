# $NetBSD: Makefile,v 1.13 2020/03/20 11:58:00 nia Exp $
#

DISTNAME=	lp_solve_5.5.2.3_source
PKGNAME=	${DISTNAME:S/_source//:S/_5/-5/}
CATEGORIES=	math devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lpsolve/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lpsolve.sourceforge.net/
COMMENT=	Mixed Integer Linear Programming (MILP) solver
#LICENSE=	LGPL, unclear which version (see lp_lib.h)

USE_GCC_RUNTIME=	yes

WRKSRC=		${WRKDIR}/lp_solve_5.5

SUBST_CLASSES+=		dl
SUBST_STAGE.dl=		pre-build
SUBST_SED.dl+=		-e s,-ldl,${DL_LIBS:Q},g
SUBST_SED.dl+=		-e s,^opts=.*,opts=\'${CFLAGS:Q}\',g
SUBST_SED.dl+=		-e s,-fpic,-fPIC,g
SUBST_VARS.dl+=		WRKDIR
SUBST_FILES.dl+=	lp_solve/ccc
SUBST_FILES.dl+=	lpsolve55/ccc
SUBST_FILES.dl+=	demo/ccc

.include "../../mk/bsd.fast.prefs.mk"

.if ${MACHINE_ARCH} == "alpha" || ${MACHINE_ARCH} == "sparc64" || \
	${MACHINE_ARCH} == "x86_64" || ${MACHINE_ARCH} == "aarch64"
LPSOLVE_ARCH=	ux64
.else
LPSOLVE_ARCH=	ux32
.endif

INSTALLATION_DIRS=	bin include/lpsolve lib

MAKE_ENV+=	DL_LDADD=${BUILDLINK_LDADD.dl:Q}

do-build:
.for dir in lp_solve lpsolve55 demo
	${RUN}${_ULIMIT_CMD}				\
	cd ${WRKSRC}/${dir} &&				\
	${SETENV} ${MAKE_ENV} ${SH} ccc
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lp_solve/bin/${LPSOLVE_ARCH}/lp_solve \
		${DESTDIR}${PREFIX}/bin
.for i in declare.h fortify.h ini.h lp_*.h lpkit.h lpsolve.h ufortify.h yacc_read.h
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${PREFIX}/include/lpsolve
.endfor
.for i in liblpsolve55.a liblpsolve55.so
	${INSTALL_LIB} ${WRKSRC}/lpsolve55/bin/${LPSOLVE_ARCH}/${i} \
		${DESTDIR}${PREFIX}/lib
.endfor
	${LN} -sf liblpsolve55.so ${DESTDIR}${PREFIX}/lib/liblpsolve55.so.1

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
