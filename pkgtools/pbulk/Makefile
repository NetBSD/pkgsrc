# $NetBSD: Makefile,v 1.67 2014/02/22 00:35:41 jperkin Exp $

DISTNAME=	pbulk-0.52
COMMENT=	Modular bulk build framework

.include "../../pkgtools/pbulk/Makefile.common"

USE_TOOLS+=	awk:run bzip2:run digest:run gzip:run make:run \
		mail:run sed:run tar:run
DEPENDS+=	rsync-[0-9]*:../../net/rsync
DEPENDS+=	pbulk-base>=0.38:../../pkgtools/pbulk-base

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && ${MAKE} == "/usr/bin/make"
TARGET_MAKE=	${MAKE}
.else
TARGET_MAKE=	$${prefix}/bin/bmake
.endif

NEATO=		${PREFIX}/bin/neato

SUBST_CLASSES+=		tools
SUBST_STAGE.tools=	post-patch
SUBST_MESSAGE.tools=	Fixing references to tools
SUBST_FILES.tools=	pbulk.conf scripts/build scripts/build-client-start \
	scripts/bulkbuild scripts/bulkbuild-rebuild scripts/bulkbuild-restart \
	scripts/client-clean \
	scripts/pkg-build scripts/pkg-up-to-date scripts/pre-build \
	scripts/report scripts/scan scripts/scan-client-start scripts/upload \
	scripts/compute-packages.awk scripts/create-broken-graph.awk \
	scripts/create-report-html.awk scripts/create-report-txt.awk \
	scripts/create-report.awk
SUBST_VARS.tools=	AWK BZIP2 CHOWN DIGEST GZIP_CMD ID MAIL_CMD NEATO \
			PBULK_CONFIG PBULK_CONFIG_VERSION PKG_ADD_CMD \
			PKG_DELETE_CMD PKG_INFO_CMD PREFIX SED SH TAR \
			TARGET_MAKE

CONF_FILES+=	share/examples/pbulk/pbulk.conf ${PKG_SYSCONFDIR}/pbulk.conf

PBULK_CONFIG=		${PKG_SYSCONFDIR}/pbulk.conf
PBULK_CONFIG_VERSION=	0.51

INSTALLATION_DIRS=	bin libexec/pbulk share/examples/pbulk
USE_BSD_MAKEFILE=	yes

BUILD_DIRS=	scripts

do-extract:
	${CP} -r ${FILESDIR}/pbulk ${WRKDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/pbulk.conf ${DESTDIR}${PREFIX}/share/examples/pbulk/pbulk.conf

.include "../../mk/bsd.pkg.mk"
