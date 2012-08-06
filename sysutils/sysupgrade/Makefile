# $NetBSD: Makefile,v 1.1 2012/08/06 17:06:17 jmmv Exp $

DISTNAME=	sysupgrade-1.0
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Automate upgrades of NetBSD
LICENSE=	modified-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}
NO_CONFIGURE=		YES

UPGRADE_SUBST+=		-e 's,@SYSUPGRADE_CACHEDIR@,${CACHEDIR},g'
UPGRADE_SUBST+=		-e 's,@SYSUPGRADE_ETCDIR@,${PKG_SYSCONFDIR},g'

BUILD_DEFS+=		VARBASE
CACHEDIR=		${VARBASE}/cache/sysupgrade
OWN_DIRS=		${CACHEDIR} root wheel

EGDIR=			${PREFIX}/share/examples/sysupgrade
CONF_FILES+=		${EGDIR}/default.conf ${PKG_SYSCONFDIR}/sysupgrade.conf

PKG_OPTIONS_VAR=	PKG_OPTIONS.sysupgrade
PKG_SUPPORTED_OPTIONS=	tests
PKG_SUGGESTED_OPTIONS=	tests

.include "../../mk/bsd.options.mk"

.if $(PKG_OPTIONS:Mtests)
TEST_PROGS=	config_test sysupgrade_test utils_test

PLIST_SUBST+=	TESTS=
.  include "../../devel/atf-libs/buildlink3.mk"

do-build: build-tests
build-tests:
	cp ${FILESDIR}/Kyuafile ${WRKSRC}
.for file in ${TEST_PROGS}
	${ECHO} '#! ${BUILDLINK_PREFIX.atf-libs}/bin/atf-sh' \
	    >${WRKSRC}/${file}
	${CAT} ${FILESDIR}/*.subr ${FILESDIR}/${file}.sh \
	    | ${SED} ${UPGRADE_SUBST} >>${WRKSRC}/${file}
	${CHMOD} +x ${WRKSRC}/${file}
.endfor

INSTALLATION_DIRS+=	tests/sysupgrade

do-install: install-tests
install-tests:
	${INSTALL_DATA} ${WRKSRC}/Kyuafile ${DESTDIR}${PREFIX}/tests/sysupgrade
.for file in ${TEST_PROGS}
	${INSTALL_SCRIPT} ${WRKSRC}/${file} \
	    ${DESTDIR}${PREFIX}/tests/sysupgrade/
.endfor

do-test:
	cd ${WRKSRC} && PATH="${WRKSRC}:${PATH}" kyua test
.else
PLIST_SUBST+=	TESTS=@comment
.endif

do-build:
	${ECHO} '#! ${SH}' >${WRKSRC}/sysupgrade
	${ECHO} 'set -e' >>${WRKSRC}/sysupgrade
	${CAT} ${FILESDIR}/*.subr ${FILESDIR}/sysupgrade.sh \
	    | ${SED} ${UPGRADE_SUBST} >>${WRKSRC}/sysupgrade
	${ECHO} 'sysupgrade_main "$${@}"' >>${WRKSRC}/sysupgrade
	${CHMOD} +x ${WRKSRC}/sysupgrade
.for file in sysupgrade.8 sysupgrade.conf.5 default.conf
	sed ${UPGRADE_SUBST} <${FILESDIR}/${file} >${WRKSRC}/${file}
.endfor

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man5 ${PKGMANDIR}/man8 \
			share/examples/sysupgrade

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sysupgrade ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/sysupgrade.8 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_MAN} ${WRKSRC}/sysupgrade.conf.5 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/
	${INSTALL_DATA} ${WRKSRC}/default.conf ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
