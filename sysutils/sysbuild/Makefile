# $NetBSD: Makefile,v 1.18 2012/07/25 12:18:22 jmmv Exp $

DISTNAME=	sysbuild-2.0
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Automates builds of NetBSD and manages source trees
LICENSE=	modified-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}
NO_CONFIGURE=		YES

BUILD_SUBST=		-e 's,@SYSBUILD_BINDIR@,${PREFIX}/bin,g'
BUILD_SUBST+=		-e 's,@SYSBUILD_EGDIR@,${EGDIR},g'
BUILD_SUBST+=		-e 's,@SYSBUILD_ETCDIR@,${PKG_SYSCONFDIR},g'

PKG_SYSCONFSUBDIR=	sysbuild
EGDIR=			${PREFIX}/share/examples/sysbuild
CONF_FILES+=		${EGDIR}/default.conf ${PKG_SYSCONFDIR}/default.conf

PKG_OPTIONS_VAR=	PKG_OPTIONS.sysbuild
PKG_SUPPORTED_OPTIONS=	tests
PKG_SUGGESTED_OPTIONS=	tests

.include "../../mk/bsd.options.mk"

.if $(PKG_OPTIONS:Mtests)
TEST_PROGS=	config_test cvs_test sysbuild_test sysbuild4cron_test utils_test

PLIST_SUBST+=	TESTS=
.  include "../../devel/atf-libs/buildlink3.mk"

do-build: build-tests
build-tests:
	cp ${FILESDIR}/Kyuafile ${WRKSRC}
.for file in ${TEST_PROGS}
	${ECHO} '#! ${BUILDLINK_PREFIX.atf-libs}/bin/atf-sh' \
	    >${WRKSRC}/${file}
	${CAT} ${FILESDIR}/*.subr ${FILESDIR}/${file}.sh \
	    | ${SED} ${BUILD_SUBST} >>${WRKSRC}/${file}
	${CHMOD} +x ${WRKSRC}/${file}
.endfor

INSTALLATION_DIRS+=	tests/sysbuild

do-install: install-tests
install-tests:
	${INSTALL_DATA} ${WRKSRC}/Kyuafile ${DESTDIR}${PREFIX}/tests/sysbuild
.for file in ${TEST_PROGS}
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${DESTDIR}${PREFIX}/tests/sysbuild/
.endfor

do-test:
	cd ${WRKSRC} && PATH="${WRKSRC}:${PATH}" kyua test
.else
PLIST_SUBST+=	TESTS=@comment
.endif

do-build:
.for file in sysbuild sysbuild4cron
	${ECHO} '#! ${SH}' >${WRKSRC}/${file}
	${ECHO} 'set -e' >>${WRKSRC}/${file}
	${CAT} ${FILESDIR}/*.subr ${FILESDIR}/${file}.sh \
	    | ${SED} ${BUILD_SUBST} >>${WRKSRC}/${file}
	${ECHO} '${file}_main "$${@}"' >>${WRKSRC}/${file}
	${CHMOD} +x ${WRKSRC}/${file}
.endfor
.for file in sysbuild.1 sysbuild4cron.1 default.conf
	sed ${BUILD_SUBST} <${FILESDIR}/${file} >${WRKSRC}/${file}
.endfor

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 share/examples/sysbuild

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sysbuild ${DESTDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/sysbuild4cron ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/sysbuild.1 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_MAN} ${WRKSRC}/sysbuild4cron.1 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
.for file in default.conf
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${EGDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
