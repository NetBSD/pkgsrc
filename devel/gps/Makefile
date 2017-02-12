# $NetBSD: Makefile,v 1.49 2017/02/12 06:25:12 ryoon Exp $
#

DISTNAME=	gps-${GPS_VERSION}
PKGREVISION=	15
CATEGORIES=	devel
MASTER_SITES=	http://downloads.dragonlace.net/src/
DISTFILES=	gps-5.2.1-1-src.tgz

MAINTAINER=	draco@marino.st
HOMEPAGE=	http://www.adacore.com/home/products/gnatpro/toolsuite/gps/
COMMENT=	GNAT Programming Studio - IDE for Ada and many other languages
LICENSE=	gnu-gpl-v2

# GPS is several years behind and normally tied to the latest Ada compiler.
# To update it would require several new and complicated dependencies.
# The maintainer has no interest in doing this work.  Somebody else is free
# to take over and use the FreeBSD Ports Collection as a reference point.
#
# The internal project support (GPR files) are illegally configured for
# today's standards and gprbuild won't let the build progress far.
# The only practical way forward to update to version 6.0.1 (which is at
# least one year behind the current version of GPS)
PKG_FAIL_REASON=	Unbuildable with gcc5-aux.  Scheduled for removal Jan 2017

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake sed perl awk pkg-config

GPS_VERSION=		5.2.1
USE_LANGUAGES=		c ada c++
MY_CONFIGURE_ENV+=	ADA_PROJECT_PATH=${APP}
MY_MAKE_ENV+=		PROCESSORS=${MAKE_JOBS:U1:Q} \
			ADA_PROJECT_PATH=${APP} \
			PATH=${PREFIX}/gcc5-aux/bin:${PATH}
MAKE_ARGS=		Build=Production
APP=			${PREFIX}/lib/gnat
WRKSRC=			${WRKDIR}/gps-release-ide-${GPS_VERSION}-src

.include "options.mk"

CONFIGURE_ARGS+=	--disable-shared --with-gmp=${PREFIX}

SUBST_CLASSES+= 	coll python
SUBST_STAGE.coll=	post-patch
SUBST_FILES.coll=	gnatlib/src/gnatcoll_readline.gpr.in
SUBST_SED.coll=		-e "s|@PREFIX@|${PREFIX}|g"
SUBST_SED.coll+=	-e "s|-rpath|${LINKER_RPATH_FLAG}|g"
SUBST_STAGE.python=	post-patch
SUBST_FILES.python=	share/plug-ins/gps_utils/console_process.py
SUBST_SED.python=	-e "s|/usr/bin/python|${PYTHONBIN}|"

GENERATE_PLIST= cd ${DESTDIR}${PREFIX}; \
		${FIND} * \( -type f -or -type l \) | ${SORT};

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MY_CONFIGURE_ENV} \
		./configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MY_MAKE_ENV} gmake ${MAKE_ARGS} default 

pre-install:
.if !empty(PKG_OPTIONS:Mpython)
	${PY_COMPILE_ALL} ${WRKSRC}/share/plug-ins
	${PY_COMPILE_ALL} ${WRKSRC}/share/library
.endif

post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/share/doc/gps/html/users_guide/_sources
	${RM} -rf ${DESTDIR}${PREFIX}/share/doc/gps/html/tutorial/_sources

BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
BUILDLINK_DEPMETHOD.gprbuild-aux=	full

.include "../../lang/python/application.mk"
.include "../../x11/gtkada/buildlink3.mk"
.include "../../textproc/xmlada/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/gprbuild-aux/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
