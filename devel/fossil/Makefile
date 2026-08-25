# $NetBSD: Makefile,v 1.96 2026/08/25 21:50:04 riastradh Exp $

DISTNAME=	fossil-src-2.27
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	devel scm
MASTER_SITES=	https://fossil-scm.org/home/tarball/version-${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.fossil-scm.org/
COMMENT=	High-reliability, distributed software configuration management
LICENSE=	2-clause-bsd

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib:Q}

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 share/doc/${PKGBASE}

LDFLAGS.Darwin+=	-liconv

.include "../../mk/bsd.prefs.mk"

.if ${USE_CROSS_COMPILE:U:tl} == "yes"
CONFIGURE_ENV+=		CC_FOR_BUILD=${NATIVE_CC:Q}
.endif

.include "options.mk"

pre-configure:
	${MKDIR} ${WRKSRC}/bld

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fossil ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fossil.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT-BSD2.txt \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/extsrc/linenoise.h \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

# https://fossil-scm.org/home/doc/tip/test/release-checklist.wiki
#
# Test results on netbsd-9:
#
#	***** Final results: 6 errors out of 42077 tests
#	***** Considered failures: settings-valid-local-anon-cookie-lifespan settings-valid-local-regexp-limit settings-valid-local-robot-exception settings-valid-global-anon-cookie-lifespan settings-valid-global-regexp-limit settings-valid-global-robot-exception
#	***** Ignored results: 0 ignored errors out of 42077 tests
#	***** Skipped tests: json merge5 set-manifest th1-docs th1-hooks th1-tcl unversioned
#

TEST_DEPENDS+=	tcl>=0:../../lang/tcl

# If USER is not defined, some tests fail and insist that you specify a
# user somehow.
#
TEST_ENV+=	USER=fossiltest

# Must run the tests out of a directory other than the source tree.
#
pre-test:
	${RUN}${MKDIR} ${WRKDIR}/test

do-test:
	${RUN}cd ${WRKDIR}/test && \
	${PKGSRC_SETENV} ${TEST_ENV} \
	    tclsh ${WRKSRC}/test/tester.tcl ${WRKSRC}/fossil

.if ${OPSYS} == "Darwin"
.include "../../converters/libiconv/buildlink3.mk"
.endif
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
