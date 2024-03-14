# $NetBSD: Makefile,v 1.2 2024/03/14 07:48:01 wiz Exp $

.include "version.mk"
PKGNAME=alire-${ALIRE_VERSION}

CATEGORIES=	devel
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alire-project/alire
COMMENT=	Ada LIbrary REpository
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c ada

.include "../../mk/bsd.prefs.mk"

DISTNAME=	${PKGNAME}
GITHUB_PROJECT=	alire
GITHUB_TYPE=	tag
GITHUB_TAG=	v${ALIRE_VERSION}
MASTER_SITES=	${MASTER_SITE_GITHUB:=alire-project/}

GITHUB_SUBMODULES+=	mosteo	aaa	dff61d2615cc6332fa6205267bae19b4d044b9da	deps/aaa
GITHUB_SUBMODULES+=	mosteo	ada-toml	da4e59c382ceb0de6733d571ecbab7ea4919b33d	deps/ada-toml
GITHUB_SUBMODULES+=	mosteo	ajunitgen	e5d01db5e7834d15c4066f0a8e33d780deae3cc9	deps/ajunitgen
GITHUB_SUBMODULES+=	mosteo	ansi-ada	dc770a5a6cdaad8668c32b0cd4625a7d648f8ca2	deps/ansi
GITHUB_SUBMODULES+=	alire-project	clic	56bbdc008e16996b6f76e443fd0165a240de1b13	deps/clic
GITHUB_SUBMODULES+=	mosteo	dirty_booleans	05c40d88ecfe109e575ec8b21dd6ffa2e61df1dc	deps/dirty_booleans
GITHUB_SUBMODULES+=	mosteo	diskflags	60729edf31816aca0036b13b2794c39a9bd0172e	deps/diskflags
GITHUB_SUBMODULES+=	alire-project	gnatcoll-core	4e663b87a028252e7e074f054f8f453661397166	deps/gnatcoll-slim
GITHUB_SUBMODULES+=	mosteo	minirest	9a9c660f9c6f27f5ef75417e7fac7061dff14d78	deps/minirest
GITHUB_SUBMODULES+=	mosteo	optional	1aa0e20bf7cd010c4b59e6ab7cc4b089790b796e	deps/optional
GITHUB_SUBMODULES+=	alire-project	semantic_versioning	cc2148cf9c8934fb557b5ae49a3f7947194fa7ee	deps/semantic_versioning
GITHUB_SUBMODULES+=	HeisenbugLtd	si_units	9329d2591b82440ccc859a53f1380ac07ea4194d	deps/si_units
GITHUB_SUBMODULES+=	alire-project	simple_logging	3505dc645f3eef6799a486aae223d37e88cfc4d5	deps/simple_logging
GITHUB_SUBMODULES+=	Fabien-Chouteau	spdx_ada	2df9b1182544359c751544e52e14c94830d99fa6	deps/spdx
GITHUB_SUBMODULES+=	mosteo	stopwatch	f607a63b714f09bbf6126de9851cbc21cf8666c9	deps/stopwatch
GITHUB_SUBMODULES+=	mosteo	toml_slicer	3e5cbdb5673b85a1da6344a41764ef1cbafe3289	deps/toml_slicer
GITHUB_SUBMODULES+=	mosteo	umwi	32496c15fe4fbb6cdab54ea11fbb0815549d2d48	deps/umwi
GITHUB_SUBMODULES+=	mosteo	uri-ada	02a0780d7757e9e79b3410c3a34960655cacea3d	deps/uri-ada
GITHUB_SUBMODULES+=	alire-project	xmlezout	1fcbd0b9303d044d8f09a8ef652afa8c0400ee8b	deps/xmlezout

GCC_REQD+=	13

.include "../../devel/gprbuild/buildlink3.mk"

CGPRDIR=	${WRKDIR}

SUBST_CLASSES+=			buildlink
SUBST_STAGE.buildlink=		post-configure
SUBST_FILES.buildlink=		../buildlink.cgpr
SUBST_MESSAGE.buildlink=	Set work directory path in config project
SUBST_VARS.buildlink=		WRKDIR

MAKE_ENV+=		ALIRE_OS=netbsd
MAKE_PROGRAM=		gprbuild
MAKE_FILE=		alr_env
MAKE_FLAGS=		-j0 -p -P
BUILD_MAKE_FLAGS=	--config=${CGPRDIR}/buildlink.cgpr

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} bin \( -type f -or -type l \) -print | ${SORT};

pre-configure:
	${RUN} ${CP} ${PKGDIR}/files/buildlink.cgpr ${CGPRDIR}/

do-build:
	${RUN} \
	cd ${WRKSRC} \
	&& env ${MAKE_ENV} \
	    ${MAKE_PROGRAM} ${MAKE_FLAGS} ${MAKE_FILE} ${BUILD_MAKE_FLAGS}

do-install:
	${RUN} \
	cd ${WRKSRC} \
	&& mkdir -p ${DESTDIR}${PREFIX}/bin \
	&& install -m0755 bin/alr ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
