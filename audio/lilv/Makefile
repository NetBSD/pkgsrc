# $NetBSD: Makefile,v 1.13 2018/11/12 03:51:42 ryoon Exp $

DISTNAME=	lilv-0.20.0
PKGREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	http://download.drobilla.net/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://drobilla.net/software/lilv/
COMMENT=	C library to make the use of LV2 plugins as simple as possible
LICENSE=	isc

#BUILD_DEPENDS+=	swig-[0-9]*:../../devel/swig2 # python --bindings BROKEN

USE_LANGUAGES=	c c++
USE_TOOLS+=	gsed pkg-config

PKGCONFIG_OVERRIDE+=	lilv.pc.in
CONFIGURE_ENV+=		LV2_PATH=${BUILDLINK_PREFIX.lv2}/lib/lv2
EGDIR=			share/examples/lilv
CONF_FILES=		${EGDIR}/lilv ${PKG_SYSCONFDIR}/bash_completion.d/lilv
MAKE_DIRS=		${PKG_SYSCONFDIR}/bash_completion.d
INSTALLATION_DIRS=	${EGDIR}

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+= lv2bench
.if ${OPSYS} != "Darwin" && ${OPSYS} != "SunOS"
# Darwin doesn't have CLOCK_GETTIME so it doesn't compile this
PLIST.lv2bench=	yes
.endif

.include "options.mk"

BUILD_OPTIONS=	${BUILD_DEBUG} ${BUILD_DOC} ${BUILD_TESTS} # --bindings BROKEN

do-configure:
	cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${PYTHONBIN} ./waf configure \
			--configdir=${PKG_SYSCONFDIR:Q} \
			--destdir=${DESTDIR} --mandir=${PREFIX}/${PKGMANDIR} \
				--default-lv2-path=${BUILDLINK_PREFIX.lv2}/lib/lv2 \
					${BUILD_OPTIONS}
do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} ./waf build

do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${PYTHONBIN} ./waf install
	${INSTALL_DATA} ${WRKSRC}/utils/lilv.bash_completion \
		${DESTDIR}${PREFIX}/${EGDIR}/lilv
	${RM} ${DESTDIR}${PKG_SYSCONFDIR}/bash_completion.d/lilv

BUILDLINK_API_DEPENDS.sratom+=	sratom>=0.4.0
.include "../../converters/sratom/buildlink3.mk"
BUILDLINK_API_DEPENDS.lv2+=	lv2>=1.8.0
.include "../../audio/lv2/buildlink3.mk"
BUILDLINK_API_DEPENDS.sord+=	sord>=0.12.0
.include "../../textproc/sord/buildlink3.mk"
BUILDLINK_API_DEPENDS.serd+=	serd>=0.14.0
.include "../../textproc/serd/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
