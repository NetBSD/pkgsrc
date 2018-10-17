# $NetBSD: Makefile,v 1.3 2018/10/17 14:44:39 hauke Exp $

DISTNAME=	tsm-8.1.6.0
PKGNAME=	${DISTNAME:C/-/8-/}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.software.ibm.com/storage/tivoli-storage-management/maintenance/client/v8r1/Linux/LinuxX86/BA/v816/
DISTFILES=	8.1.6.0-TIV-TSMBAC-LinuxX86.tar

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	https://www.ibm.com/us-en/marketplace/data-protection-and-recovery
COMMENT=	IBM Spectrum Protect (aka Tivoli Storage Manager) Client

CONFLICTS+=	tsm-[0-9]*

PKG_SYSCONFSUBDIR=	tsm
DOC_DIR=		share/doc/tsm
DOC_SRCDIR=		${WRKDIR}/.destdir/usr/pkg/emul/linux/opt/tivoli/tsm/license/baclient/tsm
EG_DIR=			share/examples/tsm
CONF_FILES=		${PREFIX}/${EG_DIR}/dsm.sys.smp ${PKG_SYSCONFDIR}/dsm.sys
CONF_FILES+=		${PREFIX}/${EG_DIR}/dsm.opt.smp ${PKG_SYSCONFDIR}/dsm.opt

PUBLIC_BINS=		dsmc

BUILD_DEFS+=		VARBASE

# See the license agreements in {PREFIX}/emul/linux/opt/tivoli/tsm/license/
RESTRICTED=		Redistribution of repackaged binaries not permitted
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=  	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

NOT_FOR_PLATFORM=	Linux-*-* NetBSD-[0-1]*-*

EMUL_PLATFORMS=		linux-x86_64
EMUL_MODULES.linux=	base
RUN_LDCONFIG=		yes

.include "../../mk/bsd.prefs.mk"

WRKSRC=			${WRKDIR}
BUILD_DIRS=		# empty

USE_TOOLS+=		rpm2pkg grep sed

RPMFILES=		${WRKDIR}/TIVsm-BA.x86_64.rpm \
			${WRKDIR}/TIVsm-API64.x86_64.rpm \
			${WRKDIR}/gskcrypt64-8.0.50.86.linux.x86_64.rpm \
			${WRKDIR}/gskssl64-8.0.50.86.linux.x86_64.rpm

EMUL_PKG_FMT=		rpm
RPM2PKG_PREFIX=		${DESTDIR}${PREFIX}
RPM2PKG_SUBPREFIX=	${EMULSUBDIR}
RPM2PKG_STRIP=		0
RPM2PKG_PLIST=		# none generated
RPM2PKG_STAGE=		do-install

PLIST_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
PLIST_SUBST+=		EMULDIR=${EMULDIR}
PLIST_SUBST+=		TSMCLIENTSUBDIR=${TSMCLIENTSUBDIR:Q}

TSMCLIENTSUBDIR=	opt/tivoli/tsm/client

# Build with PKG_OPTIONS.tsm = java for PLIST regen
PRINT_PLIST_AWK+=	{ gsub(/^.+\.jar$$/, "$${PLIST.java}&"); }
PRINT_PLIST_AWK+=	{ gsub(/^.+\/dsmj$$/, "$${PLIST.java}&"); }

SUBST_CLASSES+=         paths
SUBST_MESSAGE.paths=    Fixing hardcoded paths.
SUBST_STAGE.paths=      pre-install
SUBST_FILES.paths=      tsm_daily.sh
SUBST_SED.paths=	-e "s,%PKG_SYSCONFDIR%,${PKG_SYSCONFDIR},g"
SUBST_SED.paths+=	-e "s,%PREFIX%,${PREFIX},g"
SUBST_SED.paths+=	-e "s,%VARBASE%,${VARBASE},g"

MESSAGE_SUBST+=		EMULDIR=${EMULDIR}

INSTALLATION_DIRS+=	bin emul/linux/etc/ld.so.conf.d ${DOC_DIR} ${EG_DIR}

.include "options.mk"

post-configure:
	${CP} ${FILESDIR}/tsm_daily.sh ${WRKSRC}

do-extract:
	cd ${WRKDIR} && ${EXTRACTOR} ${DISTDIR}/${DISTFILES:Q}

post-install:
.if empty(PKG_OPTIONS:Mjava)
	for bb in `${SED} -e '/^[$$]{PLIST\\.java}/!d' -e 's/^[$$]{PLIST\\.java}//g' ${PLIST_SRC}`; do \
	    ${RM} -f ${DESTDIR}${PREFIX}/$${bb}; \
	done
.endif
	${INSTALL_DATA} ${DOC_SRCDIR}/LA_en.txt ${DESTDIR}${PREFIX}/${DOC_DIR}
	${INSTALL_DATA} ${DOC_SRCDIR}/notices.txt ${DESTDIR}${PREFIX}/${DOC_DIR}
	${INSTALL_DATA} ${DESTDIR}${EMULDIR}/${TSMCLIENTSUBDIR}/ba/bin/dsm.*.smp \
		${DESTDIR}${PREFIX}/${EG_DIR}
	${INSTALL_DATA} ${WRKSRC}/tsm_daily.sh ${DESTDIR}${PREFIX}/${EG_DIR}
	${INSTALL_DATA} ${FILESDIR}/tsm_ld.so.conf.${MACHINE_ARCH} \
		${DESTDIR}${EMULDIR}/etc/ld.so.conf.d/tsm_ld.so.conf
	${LN} -fs /..${PKG_SYSCONFDIR}/dsm.sys \
		${DESTDIR}${EMULDIR}/${TSMCLIENTSUBDIR}/ba/bin/
	${LN} -fs /..${PKG_SYSCONFDIR}/dsm.opt \
		${DESTDIR}${EMULDIR}/${TSMCLIENTSUBDIR}/ba/bin/
.for bb in ${PUBLIC_BINS}
	${LN} -fs ../${EMULSUBDIR}/${TSMCLIENTSUBDIR}/ba/bin/${bb} \
		${DESTDIR}${PREFIX}/bin/${bb}
.endfor

.include "../../mk/bsd.pkg.mk"
