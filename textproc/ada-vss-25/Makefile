# $NetBSD: Makefile,v 1.3 2025/09/22 15:23:38 dkazankov Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	vss-${GNAT_NAME}-25.0.0
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_PROJECT=	VSS
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/VSS
COMMENT=	VSS - high level string and text processing library
LICENSE=	apache-2.0

USE_TOOLS+=	gmake

USE_LANGUAGES=	ada

USE_GCC_RUNTIME=	yes

DISTFILES=	${DEFAULT_DISTFILES}

.include "../../mk/bsd.prefs.mk"

GCC_REQD+=	14

PLIST_VARS+=			shlibs

USE_PKGSRC_GCC_RUNTIME?=	no
.if ${USE_PKGSRC_GCC_RUNTIME:tl} == "yes"
PLIST.shlibs=			yes
BUILD_TARGET=			build-all-libs
INSTALL_TARGET=			install-all-libs
BUILDLINK_DEPMETHOD.xmlada-25=	full
.else
BUILD_TARGET=			build-libs-static
INSTALL_TARGET=			install-libs-static
.endif

MAKE_FLAGS=			PREFIX=${GNAT_PREFIX}
GPRFLAGS=			${GPRBUILD_OPTIONS}
BUILD_MAKE_FLAGS+=		BUILD_PROFILE=release GPRFLAGS=${GPRFLAGS:Q}

PERL5_DISTNAME=			perl-5.42.0
PERL5_DISTFILE=			${PERL5_DISTNAME}.tar.xz

.if ${PKGSRC_RUN_TEST:tl} == "yes"
DISTFILES+=			${PERL5_DISTFILE}
SITES.${PERL5_DISTFILE}=	${MASTER_SITE_PERL_CPAN:S,/modules/by-module/$,/src/5.0/,}

GITHUB_SUBMODULES+=	nigeltao	parse-number-fxx-test-data \
			55d79b184b7d8fac2e143e89dc19b766ec4e54b8	data/parse-number-fxx-test-data
GITHUB_SUBMODULES+=	json5	json5-tests	c9af328e6d77286d78b77b520c4622d588b544c0	data/json5-tests
.endif

TEST_TARGET=	check

TEST_DEPENDS+=	unicode-character-database>=15.1.0:../../textproc/unicode-character-database
TEST_DEPENDS+=	unicode-emoji>=15.1.0:../../textproc/unicode-emoji

pre-test:
	${RUN} cd ${WRKSRC}/data && \
	${LN} -s ${PREFIX}/share/unicode/ucd ucd && \
	${LN} -s ${PREFIX}/share/unicode/emoji emoji && \
	${LN} -s ${WRKDIR}/${PERL5_DISTNAME}/t/re/re_tests re_tests

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && \
	${FIND} ${GNAT_PKGBASE} \( -type f -or -type l \) -print | ${SORT};

PRINT_PLIST_AWK+=	/\/relocatable\/|\/static-pic\/|lib\/.*\.so.*/ { $$0 = "$${PLIST.shlibs}" $$0 }

.include "../../devel/gprbuild/buildlink3.mk"

.include "../../textproc/ada-xmlada-25/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
