# $NetBSD: Makefile,v 1.4 2025/04/27 10:43:42 dkazankov Exp $

PKGNAME=	alire-2.1.0
CATEGORIES=	devel
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alire-project/alire
COMMENT=	Ada LIbrary REpository
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c ada

MKPIE_SUPPORTED=	no
RELRO_SUPPORTED=	no

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	13

DISTNAME=	alire-${PKGVERSION_NOREV}
GITHUB_PROJECT=	alire
GITHUB_TAG=	v${PKGVERSION_NOREV}
MASTER_SITES=	${MASTER_SITE_GITHUB:=alire-project/}

GITHUB_SUBMODULES+=	mosteo	aaa	73d99ae1ff2f5210dc41c2ea7afebe600f9e9916	deps/aaa
GITHUB_SUBMODULES+=	mosteo	ada-toml	b0c9e6a6b96054b8afed14959e4140960285d552	deps/ada-toml
GITHUB_SUBMODULES+=	mosteo	ajunitgen	e5d01db5e7834d15c4066f0a8e33d780deae3cc9	deps/ajunitgen
GITHUB_SUBMODULES+=	mosteo	ansi-ada	0772e48d3e1f640829d142745a36b37edcd5470b	deps/ansi
GITHUB_SUBMODULES+=	alire-project	clic	56bbdc008e16996b6f76e443fd0165a240de1b13	deps/clic
GITHUB_SUBMODULES+=	mosteo	cstrings	e4d58ad90bf32bc44304197e5906a519f5a9a7bf	deps/cstrings
GITHUB_SUBMODULES+=	mosteo	den	377d1d906f83262b81b45c7989de8cd5b4aba67f	deps/den
GITHUB_SUBMODULES+=	mosteo	dirty_booleans	05c40d88ecfe109e575ec8b21dd6ffa2e61df1dc	deps/dirty_booleans
GITHUB_SUBMODULES+=	mosteo	diskflags	60729edf31816aca0036b13b2794c39a9bd0172e	deps/diskflags
GITHUB_SUBMODULES+=	alire-project	gnatcoll-core	4e663b87a028252e7e074f054f8f453661397166	deps/gnatcoll-slim
GITHUB_SUBMODULES+=	mosteo	lml_ada	3d79edaff98bc4985014c641327ceb22d655df6b	deps/lml
GITHUB_SUBMODULES+=	mosteo	minirest	9a9c660f9c6f27f5ef75417e7fac7061dff14d78	deps/minirest
GITHUB_SUBMODULES+=	mosteo	optional	7b8132a09a6c3c467409ab15d34fac605b1e5711	deps/optional
GITHUB_SUBMODULES+=	alire-project	semantic_versioning	4861e32bd8a2f0df038d3ecc9a72b6381e7a34cc	deps/semantic_versioning
GITHUB_SUBMODULES+=	HeisenbugLtd	si_units	9329d2591b82440ccc859a53f1380ac07ea4194d	deps/si_units
GITHUB_SUBMODULES+=	alire-project	simple_logging	3505dc645f3eef6799a486aae223d37e88cfc4d5	deps/simple_logging
GITHUB_SUBMODULES+=	Fabien-Chouteau	spdx_ada	2df9b1182544359c751544e52e14c94830d99fa6	deps/spdx
GITHUB_SUBMODULES+=	mosteo	stopwatch	f607a63b714f09bbf6126de9851cbc21cf8666c9	deps/stopwatch
GITHUB_SUBMODULES+=	mosteo	toml_slicer	3e5cbdb5673b85a1da6344a41764ef1cbafe3289	deps/toml_slicer
GITHUB_SUBMODULES+=	mosteo	umwi	32496c15fe4fbb6cdab54ea11fbb0815549d2d48	deps/umwi
GITHUB_SUBMODULES+=	mosteo	uri-ada	02a0780d7757e9e79b3410c3a34960655cacea3d	deps/uri-ada
GITHUB_SUBMODULES+=	alire-project	xmlezout	1fcbd0b9303d044d8f09a8ef652afa8c0400ee8b	deps/xmlezout
GITHUB_SUBMODULES+=	mosteo	yeison	88b66242f8826fd4847e0ea06c7901b753e03c74	deps/yeison

MAKE_FILE=		alr_env.gpr
MAKE_ENV=		ALIRE_OS=netbsd ALIRE_BUILD_MODE=release

# Use GPRBuild as main build system
.include "../../devel/gprbuild/gprbuild.mk"

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} bin share \( -type f -or -type l \) -print | ${SORT};

.include "../../mk/bsd.pkg.mk"
