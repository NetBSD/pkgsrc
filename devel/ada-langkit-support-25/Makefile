# $NetBSD: Makefile,v 1.2 2025/09/12 17:49:49 dkazankov Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	langkit-support-${GNAT_NAME}-25.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	langkit
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/langkit
COMMENT=	Ada support package for Langkit, release 25
LICENSE=	apache-2.0

USE_LANGUAGES=	ada

USE_GCC_RUNTIME=	yes

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	14

PLIST_VARS+=	shlibs

USE_PKGSRC_GCC_RUNTIME?=			no
.if ${USE_PKGSRC_GCC_RUNTIME:tl} == "yes"
PLIST.shlibs=					yes
LIBRARY_TYPES=					static,static-pic,relocatable
BUILDLINK_DEPMETHOD.xmlada-25=			full
BUILDLINK_DEPMETHOD.libgpr-25=			full
BUILDLINK_DEPMETHOD.gnatcoll-core-25=		full
BUILDLINK_DEPMETHOD.gnatcoll-bindings-25=	full
BUILDLINK_DEPMETHOD.adasat-25=			full
BUILDLINK_DEPMETHOD.vss-25=			full
BUILDLINK_DEPMETHOD.prettier-ada-25=		full
.else
LIBRARY_TYPES=					static
.endif

MAKE_PROGRAM=		${PYTHONBIN:Q} manage.py

do-build:
	${RUN}${_ULIMIT_CMD} \
	cd ${WRKSRC} && \
	${PKGSRC_SETENV} ${MAKE_ENV} \
	${MAKE_PROGRAM} build-langkit-support \
	    --build-mode=prod \
	    --library-types=${LIBRARY_TYPES} \
	    --gargs=${GPRBUILD_OPTIONS:S/\${CFLAGS}/${CFLAGS}/:S/\${LDFLAGS}/${LDFLAGS}/:Q}

do-install:
	${RUN}${_ULIMIT_CMD} \
	cd ${WRKSRC} && \
	${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
	${MAKE_PROGRAM} install-langkit-support \
	    --build-mode=prod \
	    --library-types=${LIBRARY_TYPES} \
	    ${DESTDIR}${GNAT_PREFIX}

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} ${GNAT_PKGBASE} \( -type f -or -type l \) -print | ${SORT};

PRINT_PLIST_AWK+=	/\.relocatable\/|\.static-pic\/|lib\/.*\.${SHLIB_EXT}.*/ { $$0 = "$${PLIST.shlibs}" $$0 }

.include "../../devel/gprbuild/buildlink3.mk"

.include "../../textproc/ada-xmlada-25/buildlink3.mk"
.include "../../devel/ada-libgpr-25/buildlink3.mk"
.include "../../devel/ada-gnatcoll-core-25/buildlink3.mk"
.include "../../devel/ada-gnatcoll-bindings-25/buildlink3.mk"
.include "../../textproc/ada-vss-25/buildlink3.mk"
.include "../../textproc/ada-prettier-ada-25/buildlink3.mk"
.include "../../math/ada-adasat-25/buildlink3.mk"

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61:../../devel/py-setuptools

TOOL_DEPENDS+=	${PYPKGPREFIX}-mako>=1.1.2:../../devel/py-mako
TOOL_DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
TOOL_DEPENDS+=	${PYPKGPREFIX}-funcy>=1.14:../../devel/py-funcy
TOOL_DEPENDS+=	${PYPKGPREFIX}-docutils>=0.16:../../textproc/py-docutils
TOOL_DEPENDS+=	${PYPKGPREFIX}-e3-core>=22.6.0:../../devel/py-e3-core

.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
