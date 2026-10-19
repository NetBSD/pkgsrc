# $NetBSD: Makefile,v 1.1 2026/10/19 10:12:30 sborrill Exp $
LTP_VERSION=	20260529

PKGNAME=	compat_linux_test_project-${LTP_VERSION}-0.10
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=linux-test-project/}ltp/releases/download/${LTP_VERSION}/
DISTFILES=	ltp-full-${LTP_VERSION}.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Package to build and run the Linux Test Project tests on NetBSD
LICENSE=	2-clause-bsd

NO_CONFIGURE=	YES

USE_TOOLS+=	gmake pax
WRKSRC=		${WRKDIR}/ltp-full-${LTP_VERSION}


BUILD_DEPENDS+=	suse_gcc12>=15.5:../../emulators/suse15_gcc12
DEPENDS+=	e2fsprogs-[0-9]*:../../sysutils/e2fsprogs

EMUL_PLATFORMS=	linux-x86_64
EMUL_REQD+=	suse>=15.5

LTP_PREFIX=	libexec/compat_linux_test_project
REFLOGS_NAME=	${OPSYS}-${OS_VERSION:C/\..*//}-${MACHINE_ARCH}
REFLOGS_TMP=	${WRKDIR}/reflogs

EGDIR=			${PREFIX}/share/examples/compat_linux_test_project
INSTALLATION_DIRS=	bin ${LTP_PREFIX}
INSTALLATION_DIRS+=	share/examples/compat_linux_test_project

GENERATE_PLIST+=	cd ${DESTDIR}${PREFIX}/${LTP_PREFIX} && \
			    find . -type f | sed 's|^\./|${LTP_PREFIX}/|' ;

do-build:
	cd ${WRKSRC} && ${SH} ${FILESDIR}/compile.sh --ltp-version ${LTP_VERSION} \
	    --dest ${WRKSRC}/${LTP_PREFIX} --link-mode "${LINK_MODE}"
	${INSTALL_DATA} ${FILESDIR}/linux_config ${WRKSRC}/${LTP_PREFIX}/linux_config
	if [ -f ${FILESDIR}/reference_logs/${REFLOGS_NAME}.shar ]; then \
		cd ${WRKSRC}/${LTP_PREFIX} && \
		${SH} ${FILESDIR}/reference_logs/${REFLOGS_NAME}.shar && \
		${MV} ${REFLOGS_NAME} reference_logs; \
	fi

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/compat_tester.sh \
            ${DESTDIR}${PREFIX}/bin/compat_linux_test_project
	cd ${WRKSRC}/${LTP_PREFIX} && \
            pax -rw . ${DESTDIR}${PREFIX}/${LTP_PREFIX}

post-install:
	${INSTALL_DATA} ${FILESDIR}/examples/*.txt ${DESTDIR}${EGDIR}/

.PHONY: update-reference-logs
update-reference-logs:
	${TEST} -d "${REFLOGS_DIR}" || { ${ECHO} "Usage: make update-reference-logs REFLOGS_DIR=/path/to/logs"; exit 1; }
	${MKDIR} ${WRKDIR} ${FILESDIR}/reference_logs
	${RM} -rf ${WRKDIR}/${REFLOGS_NAME}
	${CP} -R ${REFLOGS_DIR} ${WRKDIR}/${REFLOGS_NAME}
	cd ${WRKDIR} && shar `find ${REFLOGS_NAME} -print` \
		> ${FILESDIR}/reference_logs/${REFLOGS_NAME}.shar
	${ECHO} "Wrote ${FILESDIR}/reference_logs/${REFLOGS_NAME}.shar"

.PHONY: generate-reference-logs
generate-reference-logs:
	${TEST} "`id -u`" = 0 || { ${ECHO} "Must be run as root"; exit 1; }
	pkg_info -qe ${PKGNAME} || { ${eCHO} "Install ${PKGNAME} first"; exit 1; }
	${MKDIR} ${WRKDIR}
	${RM} -rf ${REFLOGS_TMP}
	${PREFIX}/bin/compat_linux_test_project -r -d ${REFLOGS_TMP}
	${MAKE} update-reference-logs REFLOGS_DIR=${REFLOGS_TMP}

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
