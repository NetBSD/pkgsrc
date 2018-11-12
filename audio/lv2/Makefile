# $NetBSD: Makefile,v 1.10 2018/11/12 03:51:08 ryoon Exp $

DISTNAME=	lv2-1.12.0
PKGREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	http://lv2plug.in/spec/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lv2plug.in/
COMMENT=	Open standard for audio plugins, used by hundreds of plugins
LICENSE=	isc

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	lv2/lv2plug.in/ns/lv2core/lv2core.pc.in
PKGCONFIG_OVERRIDE+=	lv2.pc.in

PYTHON_SELF_CONFLICT=	yes
REPLACE_PYTHON+=	lv2specgen/lv2specgen.py

.include "options.mk"

BUILD_OPTIONS=	${BUILD_DEBUG} ${BUILD_DOC} ${BUILD_TESTS} ${BUILD_VALGRIND}

do-configure:
	cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${PYTHONBIN} ./waf configure \
			--destdir=${DESTDIR} --mandir=${PREFIX}/${PKGMANDIR} \
				--copy-headers ${BUILD_OPTIONS}
do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} ./waf build

do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${PYTHONBIN} ./waf install

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.8.10
.include "../../graphics/cairo/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2++=	gtk2+>=2.18.0
.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libsndfile+=	libsndfile>=1.0.0
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
