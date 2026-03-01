# $NetBSD: Makefile,v 1.3 2026/03/01 12:38:35 gdt Exp $

DISTNAME=	${GITHUB_PROJECT}
PKGNAME=	${GITHUB_PROJECT}-13-13.3.0
PKGREVISION=	2
CATEGORIES=	lang devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	spark2014
# latest fsf-13 branch commit
GITHUB_TAG=	12db22e854defa9d1c993ef904af1e72330a68ca
DISTFILES=	${DEFAULT_DISTFILES}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/spark2014
COMMENT=	SPARK 2014 toolset, FSF release 13
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c ada
# GNAT major release must match SPARK2014 major release
GCC_REQD+=	13

USE_TOOLS+=	gmake

HAS_CONFIGURE=	yes

MKPIE_SUPPORTED=	no
RELRO_SUPPORTED=	no

GITHUB_SUBMODULES+=	AdaCore	alt-ergo	be23b7992464438d6b654d9e36e6917748862130	alt-ergo
GITHUB_SUBMODULES+=	AdaCore	cvc5		98b5fb70e8a94fd258bfc959c4a6fd0cc3537564	cvc5
GITHUB_SUBMODULES+=	AdaCore	why3		52b6a590ba9bfc64aa0d22b41715358f26124a1f	why3
GITHUB_SUBMODULES+=	AdaCore	z3		7e79f0deb7c9d43f7637113be5b99391f14fcc2e	z3

# Do not use GNAT 13.4 sources
GCC_DISTNAME=		gcc-${PKGVERSION_NOREV}
GCC_EXTRACT_SUFFIX=	.tar.xz
GCC_DISTFILE=		${GCC_DISTNAME}${GCC_EXTRACT_SUFFIX}

DISTFILES+=		${GCC_DISTFILE}
SITES.${GCC_DISTFILE}=	${MASTER_SITE_GNU:=gcc/${GCC_DISTNAME}/}

.include "../../mk/bsd.prefs.mk"

CONFIG_SHELL=		${MAKE_PROGRAM}
CONFIGURE_ARGS+=	DESTDIR=${DESTDIR} PREFIX=${GNAT_PREFIX}
CONFIGURE_SCRIPT=	setup

MAKE_FLAGS+=		DESTDIR=${DESTDIR} PREFIX=${GNAT_PREFIX}

INSTALL_TARGET=		install-all

SUBST_CLASSES+=			interpreter
SUBST_STAGE.interpreter=	pre-configure
SUBST_FILES.interpreter=	benchmark_script/*
SUBST_MESSAGE.interpreter=	Fix interpreter in ${SUBST_FILES.interpreter}
SUBST_SED.interpreter=		-e 's,/bin/bash,/bin/sh,g'

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
	${FIND} ${GNAT_PKGBASE} \( -type f -or -type l \) -print | ${SORT};

.include "../../devel/gprbuild/buildlink3.mk"

.include "../../textproc/ada-xmlada-24/buildlink3.mk"
.include "../../devel/ada-libgpr-24/buildlink3.mk"
.include "../../devel/ada-gnatcoll-core-24/buildlink3.mk"

.include "../../lang/python/tool.mk"

BUILDLINK_DEPMETHOD.ocaml=			build
.include "../../lang/ocaml/ocaml.mk"
BUILDLINK_DEPMETHOD.ocamlgraph=			build
.include "../../devel/ocamlgraph/buildlink3.mk"
BUILDLINK_DEPMETHOD.menhir=			build
.include "../../devel/menhir/buildlink3.mk"
BUILDLINK_DEPMETHOD.ocaml-zarith=		build
.include "../../math/ocaml-zarith/buildlink3.mk"
BUILDLINK_DEPMETHOD.ocaml-zip=			build
.include "../../archivers/ocaml-zip/buildlink3.mk"
BUILDLINK_DEPMETHOD.ocaml-ocplib-simplex=	build
.include "../../math/ocaml-ocplib-simplex/buildlink3.mk"
BUILDLINK_DEPMETHOD.ocaml-num=	build
.include "../../math/ocaml-num/buildlink3.mk"
BUILDLINK_DEPMETHOD.ocaml-yojson=	build
.include "../../devel/ocaml-yojson/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
