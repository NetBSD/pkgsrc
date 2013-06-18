# $NetBSD: Makefile,v 1.4 2013/06/18 13:23:22 jmmv Exp $

DISTNAME=	shtk-1.2
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Shell-scripting modules that provide common functionality
LICENSE=	modified-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}
NO_CONFIGURE=		YES

BUILD_SUBST+=		-e 's,@SHTK_MODULESDIR@,${PREFIX}/share/shtk,g'
BUILD_SUBST+=		-e 's,@SHTK_SHELL@,${SH},g'
BUILD_SUBST+=		-e 's,@SHTK_VERSION@,${PKGVERSION},g'

PKG_OPTIONS_VAR=	PKG_OPTIONS.shtk
PKG_SUPPORTED_OPTIONS=	tests
PKG_SUGGESTED_OPTIONS=	tests

.include "../../mk/bsd.options.mk"

.if $(PKG_OPTIONS:Mtests)
TEST_PROGS=	base_test cli_test config_test cvs_test list_test \
		process_test shtk_test

PLIST_SUBST+=	TESTS=
.  include "../../devel/atf-libs/buildlink3.mk"

do-build: build-tests
build-tests: build-shtk
	cp ${FILESDIR}/Kyuafile ${WRKSRC}
.for file in ${TEST_PROGS}
	SHTK_MODULESDIR=${FILESDIR} ${WRKSRC}/shtk build \
	    -s ${BUILDLINK_PREFIX.atf-libs}/bin/atf-sh \
	    -m '' -o ${WRKSRC}/${file} ${FILESDIR}/${file}.sh
.endfor

INSTALLATION_DIRS+=	tests/shtk

do-install: install-tests
install-tests:
	${INSTALL_DATA} ${WRKSRC}/Kyuafile ${DESTDIR}${PREFIX}/tests/shtk
.for file in ${TEST_PROGS}
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${DESTDIR}${PREFIX}/tests/shtk/
.endfor

do-test:
	cd ${WRKSRC} && PATH="${WRKSRC}:${PATH}" SHTK_MODULESDIR="${FILESDIR}" \
	    kyua test
.else
PLIST_SUBST+=	TESTS=@comment
.endif

do-build: build-shtk
build-shtk:
	${SED} ${BUILD_SUBST} ${FILESDIR}/shtk.sh >${WRKSRC}/shtk
	${CHMOD} +x ${WRKSRC}/shtk
	${SED} ${BUILD_SUBST} ${FILESDIR}/shtk.1 >${WRKSRC}/shtk.1

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 share/shtk

do-install: install-shtk
install-shtk:
	${INSTALL_SCRIPT} ${WRKSRC}/shtk ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/shtk.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.for module in base bootstrap cli config cvs list process
	${INSTALL_DATA} ${FILESDIR}/${module}.subr ${DESTDIR}${PREFIX}/share/shtk
.endfor

.include "../../mk/bsd.pkg.mk"
