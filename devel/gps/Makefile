# $NetBSD: Makefile,v 1.31 2013/10/10 14:42:04 ryoon Exp $
#

DISTNAME=	gps-${GPS_VERSION}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://downloads.dragonlace.net/src/
DISTFILES=	gps-5.2.1-1-src.tgz

MAINTAINER=	draco@marino.st
HOMEPAGE=	http://www.adacore.com/home/products/gnatpro/toolsuite/gps/
COMMENT=	GNAT Programming Studio - IDE for Ada and many other languages
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake sed perl awk pkg-config

GPS_VERSION=		5.2.1
USE_LANGUAGES=		c ada c++
MY_CONFIGURE_ENV+=	ADA_PROJECT_PATH=${APP}
MY_MAKE_ENV+=		PROCESSORS=${MAKE_JOBS} \
			ADA_PROJECT_PATH=${APP}
APP=			${PREFIX}/lib/gnat
WRKSRC=			${WRKDIR}/gps-release-ide-${GPS_VERSION}-src
MAKE_JOBS_SAFE=		yes

.include "options.mk"

CONFIGURE_ARGS+=	--disable-shared --with-gmp=${PREFIX}

SUBST_CLASSES+= 	coll python
SUBST_STAGE.coll=	post-patch
SUBST_FILES.coll=	gnatlib/src/gnatcoll_readline.gpr.in
SUBST_SED.coll=		-e "s|@PREFIX@|${PREFIX}|g"
SUBST_STAGE.python=	post-patch
SUBST_FILES.python=	share/plug-ins/gps_utils/console_process.py
SUBST_SED.python=	-e "s|/usr/bin/python|${PYTHONBIN}|"

GENERATE_PLIST= cd ${DESTDIR}${PREFIX}; \
		${FIND} * \( -type f -or -type l \) | ${SORT};

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MY_CONFIGURE_ENV} \
		./configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MY_MAKE_ENV} gmake default 

pre-install:
.if !empty(PKG_OPTIONS:Mpython)
	${PY_COMPILE_ALL} ${WRKSRC}/share/plug-ins
	${PY_COMPILE_ALL} ${WRKSRC}/share/library
.endif

post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/share/doc/gps/html/users_guide/_sources
	${RM} -rf ${DESTDIR}${PREFIX}/share/doc/gps/html/tutorial/_sources
	cd ${DESTDIR}${PREFIX}; ${FIND} * -type d -empty -print | xargs rmdir

DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

.include "../../lang/python/application.mk"
.include "../../x11/gtkada/buildlink3.mk"
.include "../../textproc/xmlada/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/gprbuild-aux/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
