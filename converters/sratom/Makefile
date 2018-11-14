# $NetBSD: Makefile,v 1.10 2018/11/14 22:21:11 kleink Exp $

DISTNAME=	sratom-0.4.6
PKGREVISION=	8
CATEGORIES=	converters
MASTER_SITES=	http://download.drobilla.net/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://drobilla.net/software/sratom/
COMMENT=	Library for serialising LV2 atoms to/from RDF
LICENSE=	isc

USE_TOOLS+=	gsed pkg-config

PKGCONFIG_OVERRIDE+=	sratom.pc.in

.include "options.mk"

BUILD_OPTIONS=	${BUILD_DEBUG} ${BUILD_DOC} ${BUILD_TESTS}

do-configure:
	cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${PYTHONBIN} ./waf configure \
			--destdir=${DESTDIR} --mandir=${PREFIX}/${PKGMANDIR} \
				${BUILD_OPTIONS}
do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} ./waf build

do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${PYTHONBIN} ./waf install

BUILDLINK_API_DEPENDS.sord+=	sord>=0.12.0
.include "../../textproc/sord/buildlink3.mk"
BUILDLINK_API_DEPENDS.serd+=	serd>=0.14.0
.include "../../textproc/serd/buildlink3.mk"
BUILDLINK_API_DEPENDS.lv2+=	lv2>=1.8.1
.include "../../audio/lv2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
