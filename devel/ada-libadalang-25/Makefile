# $NetBSD: Makefile,v 1.2 2025/09/21 05:32:56 dkazankov Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	${GITHUB_PROJECT}-${GNAT_NAME}-25.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	libadalang
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/libadalang
COMMENT=	Library for parsing and semantic analysis of Ada code
LICENSE=	apache-2.0

USE_TOOLS=	tar bzip2

USE_LANGUAGES=	c ada

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
BUILDLINK_DEPMETHOD.libgpr2-25=			full
BUILDLINK_DEPMETHOD.vss-25=			full
BUILDLINK_DEPMETHOD.prettier-ada-25=		full
BUILDLINK_DEPMETHOD.langkit-support-25=		full
.else
LIBRARY_TYPES=					static
.endif

MAKE_PROGRAM=		${PYTHONBIN:Q} manage.py

PREGENERATED_DISTNAME=	libadalang-pregenerated-${PKGVERSION_NOREV}.tar.bz2

post-extract:
	if [ -f ${PKGDIR}/files/${PREGENERATED_DISTNAME} ]; then \
	    ${MKDIR} ${WRKDIR}/${DISTNAME}/build && \
	    cd ${WRKDIR}/${DISTNAME}/build && \
		${TAR} -xf ${PKGDIR}/files/${PREGENERATED_DISTNAME} ; \
	fi

TOOL_DEPENDS+=	${PYPKGPREFIX}-langkit>=25.0.0:../../devel/py-langkit
TOOL_DEPENDS+=	${PYPKGPREFIX}-liblktlang>=25.0.0:../../devel/py-liblktlang

# Also add all langkit dependencies
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61:../../devel/py-setuptools

TOOL_DEPENDS+=	${PYPKGPREFIX}-mako>=1.1.2:../../devel/py-mako
TOOL_DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
TOOL_DEPENDS+=	${PYPKGPREFIX}-funcy>=1.14:../../devel/py-funcy
TOOL_DEPENDS+=	${PYPKGPREFIX}-docutils>=0.16:../../textproc/py-docutils
TOOL_DEPENDS+=	${PYPKGPREFIX}-e3-core>=22.6.0:../../devel/py-e3-core

pre-build:
	if ! [ -d ${WRKDIR}/${DISTNAME}/build ]; then \
	    cd ${WRKSRC} && \
		${MAKE_PROGRAM} generate && \
	    cd ${WRKSRC}/build && \
		${TAR} -jcf ${WRKDIR}/${PREGENERATED_DISTNAME} . ; \
	fi

do-build:
	${RUN}${_ULIMIT_CMD} \
	cd ${WRKSRC} && \
	${PKGSRC_SETENV} ${MAKE_ENV} \
	${MAKE_PROGRAM} build \
	    --build-mode=prod \
	    --library-types=${LIBRARY_TYPES} \
	    --gargs=${GPRBUILD_OPTIONS:S/\${CFLAGS}/${CFLAGS}/:S/\${LDFLAGS}/${LDFLAGS}/:Q}

do-install:
	${RUN}${_ULIMIT_CMD} \
	cd ${WRKSRC} && \
	${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
	${MAKE_PROGRAM} install \
	    ${DESTDIR}${GNAT_PREFIX} \
	    --build-mode=prod \
	    --library-types=${LIBRARY_TYPES}
# Remove folders and files copied by langkit install
	cd ${DESTDIR}${GNAT_PREFIX} && \
	rm -R java && rm -R ocaml && rm -R python && rmdir lib/windows && \
	rm bin/lal_playground && rm share/examples/libadalang/*.py

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} ${GNAT_PKGBASE} \( -type f -or -type l \) -print | ${SORT};

PRINT_PLIST_AWK+=	/\.relocatable\/|\.static-pic\/|lib\/.*\.${SHLIB_EXT}.*/ { $$0 = "$${PLIST.shlibs}" $$0 }

CHECK_PIE_SKIP+=	${GNAT_PKGBASE}/bin/*

.include "../../devel/gprbuild/buildlink3.mk"

.include "../../textproc/ada-xmlada-25/buildlink3.mk"
.include "../../devel/ada-libgpr-25/buildlink3.mk"
.include "../../devel/ada-gnatcoll-core-25/buildlink3.mk"
.include "../../devel/ada-gnatcoll-bindings-25/buildlink3.mk"
.include "../../math/ada-adasat-25/buildlink3.mk"
.include "../../devel/ada-libgpr2-25/buildlink3.mk"
.include "../../textproc/ada-vss-25/buildlink3.mk"
.include "../../textproc/ada-prettier-ada-25/buildlink3.mk"

.include "../../devel/ada-langkit-support-25/buildlink3.mk"

# LIBGPR2 dependencies
.include "../../devel/gmp/buildlink3.mk"

USE_GNU_ICONV=	yes
.include "../../converters/libiconv/buildlink3.mk"

.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
