# $NetBSD: Makefile,v 1.4 2012/09/07 12:48:32 jmmv Exp $

DISTNAME=	sysupgrade-1.3
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

BUILD_SUBST+=		-e 's,@SYSUPGRADE_CACHEDIR@,${CACHEDIR},g'
BUILD_SUBST+=		-e 's,@SYSUPGRADE_ETCDIR@,${PKG_SYSCONFDIR},g'

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
PLIST_SUBST+=	TESTS=
.  include "../../devel/atf-libs/buildlink3.mk"

BUILD_SUBST+=		-e 's,@ATF_SH@,${BUILDLINK_PREFIX.atf-libs}/bin/atf-sh,g'

do-build: build-tests
build-tests:
	cp ${FILESDIR}/Kyuafile ${WRKSRC}
	sed ${BUILD_SUBST} ${FILESDIR}/sysupgrade_test.sh \
	    >${WRKSRC}/sysupgrade_test
	chmod +x ${WRKSRC}/sysupgrade_test

INSTALLATION_DIRS+=	tests/sysupgrade

do-install: install-tests
install-tests:
	${INSTALL_DATA} ${WRKSRC}/Kyuafile ${DESTDIR}${PREFIX}/tests/sysupgrade
	${INSTALL_SCRIPT} ${WRKSRC}/sysupgrade_test \
	    ${DESTDIR}${PREFIX}/tests/sysupgrade/

do-test:
	cd ${WRKSRC} && PATH="${WRKSRC}:${PATH}" kyua test
.else
PLIST_SUBST+=	TESTS=@comment
.endif

do-build:
	sed ${BUILD_SUBST} ${FILESDIR}/sysupgrade.sh \
	    | ${BUILDLINK_PREFIX.shtk}/bin/shtk build \
	    -s ${SH} -m sysupgrade_main -o ${WRKSRC}/sysupgrade -
.for file in sysupgrade.8 sysupgrade.conf.5 default.conf
	sed ${BUILD_SUBST} <${FILESDIR}/${file} >${WRKSRC}/${file}
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

.include "../../devel/shtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
