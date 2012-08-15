# $NetBSD: Makefile,v 1.19 2012/08/15 21:20:14 jmmv Exp $

DISTNAME=	sysbuild-2.1
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
TEST_PROGS=	sysbuild_test sysbuild4cron_test

PLIST_SUBST+=	TESTS=
.  include "../../devel/atf-libs/buildlink3.mk"

BUILD_SUBST+=		-e 's,@ATF_SH@,${BUILDLINK_PREFIX.atf-libs}/bin/atf-sh,g'

do-build: build-tests
build-tests:
	cp ${FILESDIR}/Kyuafile ${WRKSRC}
.for file in ${TEST_PROGS}
	sed ${BUILD_SUBST} <${FILESDIR}/${file}.sh >${WRKSRC}/${file}
	chmod +x ${WRKSRC}/${file}
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
	sed ${BUILD_SUBST} ${FILESDIR}/${file}.sh \
	    | ${BUILDLINK_PREFIX.shtk}/bin/shtk build \
	    -s ${SH} -m ${file}_main -o ${WRKSRC}/${file} -
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

.include "../../devel/shtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
