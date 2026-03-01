# $NetBSD: Makefile,v 1.5 2026/03/01 12:38:35 gdt Exp $

DISTNAME=	${GITHUB_PROJECT}-fsf-14
PKGNAME=	${GITHUB_PROJECT}-14-14.2.0
PKGREVISION=	3
CATEGORIES=	lang devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	spark2014
GITHUB_TAG=	fsf-14
DISTFILES=	${DEFAULT_DISTFILES}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/spark2014
COMMENT=	SPARK 2014 toolset, FSF release 14
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c ada

USE_TOOLS+=	gmake

HAS_CONFIGURE=	yes

CHECK_PIE_SKIP+=	gcc14-gnat/bin/*

GITHUB_SUBMODULES+=	AdaCore	why3	fsf-14	why3

# Do not use GNAT 14.3 sources
GCC_DISTNAME=		gcc-${PKGVERSION_NOREV}
GCC_EXTRACT_SUFFIX=	.tar.xz
GCC_DISTFILE=		${GCC_DISTNAME}${GCC_EXTRACT_SUFFIX}

DISTFILES+=		${GCC_DISTFILE}
MASTER_SITES+=		${MASTER_SITE_GNU:=gcc/${GCC_DISTNAME}/}

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	14

CONFIG_SHELL=		${MAKE_PROGRAM}
CONFIGURE_ARGS+=	DESTDIR=${DESTDIR} PREFIX=${PREFIX}/gcc14-gnat
CONFIGURE_SCRIPT=	setup

MAKE_FLAGS+=		DESTDIR=${DESTDIR} PREFIX=${PREFIX}/gcc14-gnat

INSTALL_TARGET=		install-all

SUBST_CLASSES+=		version
SUBST_MESSAGE.version=	Replace version in ${SUBST_FILES.version}
SUBST_STAGE.version=	pre-configure
SUBST_FILES.version=	Makefile spark2014vsn.ads
SUBST_SED.version=	-e "s,0.0w,FSF 14.0,"

.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+=		sha256
SUBST_MESSAGE.sha256=	Replace sha256sum in ${SUBST_FILES.sha256}
SUBST_STAGE.sha256=	pre-configure
SUBST_FILES.sha256=	Makefile
SUBST_SED.sha256=	-e "s,sha256sum,sha256 -n,"

SUBST_CLASSES+=		install
SUBST_MESSAGE.install=	Remove -C in ${SUBST_FILES.install}
SUBST_STAGE.install=	pre-configure
SUBST_FILES.install=	why3/Makefile.in
SUBST_SED.install=	-e "s,do install -C,do install,"

SUBST_CLASSES+=			interpreter
SUBST_STAGE.interpreter=	pre-configure
SUBST_FILES.interpreter=	benchmark_script/*
SUBST_MESSAGE.interpreter=	Fix interpreter in ${SUBST_FILES.interpreter}
SUBST_SED.interpreter=		-e 's,/bin/bash,/bin/sh,g'
.endif

post-extract:
# Link GNAT sources to main build tree
	${RUN} cd ${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG} \
	&& ${LN} -s ../../${GCC_DISTNAME}/gcc/ada gnat2why/gnat_src

post-install:
# Fix group write mode
	cd ${DESTDIR}${PREFIX} && \
	${CHMOD} -R -P g-w ./*

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} gcc14-gnat \( -type f -or -type l \) -print | ${SORT};

.include "../../devel/gprbuild/buildlink3.mk"

.include "../../textproc/ada-xmlada-25/buildlink3.mk"
.include "../../math/ada-adasat-25/buildlink3.mk"
.include "../../devel/ada-libgpr-25/buildlink3.mk"
.include "../../devel/ada-gnatcoll-core-25/buildlink3.mk"
.include "../../devel/ada-gnatcoll-bindings-25/buildlink3.mk"
.include "../../devel/ada-libgpr2-25/buildlink3.mk"

.include "../../lang/python/tool.mk"

OCAML_SRC=		${WRKSRC}/why3

BUILDLINK_DEPMETHOD.ocaml=			build
.include "../../lang/ocaml/ocaml.mk"

BUILDLINK_DEPMETHOD.menhir=			build
.include "../../devel/menhir/buildlink3.mk"
BUILDLINK_DEPMETHOD.ocaml-num=			build
.include "../../math/ocaml-num/buildlink3.mk"
BUILDLINK_DEPMETHOD.ocamlgraph=			build
.include "../../devel/ocamlgraph/buildlink3.mk"
BUILDLINK_DEPMETHOD.ocaml-re=			build
.include "../../devel/ocaml-re/buildlink3.mk"
BUILDLINK_DEPMETHOD.ocaml-seq=			build
.include "../../devel/ocaml-seq/buildlink3.mk"
BUILDLINK_DEPMETHOD.ocaml-yojson=		build
.include "../../devel/ocaml-yojson/buildlink3.mk"
BUILDLINK_DEPMETHOD.ocaml-zarith=		build
.include "../../math/ocaml-zarith/buildlink3.mk"
BUILDLINK_DEPMETHOD.ocaml-sexplib=		build
.include "../../devel/ocaml-sexplib/buildlink3.mk"
BUILDLINK_DEPMETHOD.ocaml-ppx_sexp_conv=	build
.include "../../devel/ocaml-ppx_sexp_conv/buildlink3.mk"
BUILDLINK_DEPMETHOD.ocaml-ppx_deriving=		build
.include "../../devel/ocaml-ppx_deriving/buildlink3.mk"

# libgpr2 dependencies
.include "../../devel/gmp/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
