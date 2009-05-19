# $NetBSD: Makefile,v 1.45 2009/05/19 08:59:33 wiz Exp $

DISTNAME=		vlp4510e
PKGNAME=		uvscan-5.10
PKGREVISION=		2
CATEGORIES=		security
MASTER_SITES=		http://download.nai.com/products/evaluation/virusscan/english/cmdline/linux/v5.10/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.mcafee.com/us/enterprise/products/anti_virus/file_servers_desktops/virusscan_command_line_scanner_windows_unix.html
COMMENT=		Evaluation version of a DOS/Windows file virus scanner
LICENSE=		uvscan-license

RESTRICTED=		restrictive 30 day evaluation license
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

CONFLICTS=		uvscan-dat-[0-9]*

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	compat

WRKSRC=			${WRKDIR}
BUILD_DIRS=		# empty

DOCDIR=			${PREFIX}/share/doc/uvscan
EGDATDIR=		${PREFIX}/share/examples/uvscan
UVSCANDIR=		${PREFIX}/libexec/uvscan
DATFILES=		clean.dat internet.dat names.dat scan.dat pkgdesc.ini

FILES_SUBST+=		UVSCANDIR=${UVSCANDIR:Q}
FILES_SUBST+=		DATFILES=${DATFILES:Q}

CONF_FILES=		${EGDATDIR}/clean.dat ${UVSCANDIR}/clean.dat
CONF_FILES+=		${EGDATDIR}/names.dat ${UVSCANDIR}/names.dat
CONF_FILES+=		${EGDATDIR}/scan.dat ${UVSCANDIR}/scan.dat
REQD_DIRS=		${UVSCANDIR}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 sbin

USE_TOOLS+=		gtar:run

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	update_dat.sh uvscan.sh
SUBST_VARS.paths=	AWK BASENAME CP DATFILES ECHO GTAR MKDIR MV	\
			PREFIX RM SED UVSCANDIR
SUBST_STAGE.paths=	post-patch

post-extract:
	${CP} ${FILESDIR}/update_dat.sh ${WRKSRC}/update_dat.sh
	${CP} ${FILESDIR}/uvscan.sh ${WRKSRC}/uvscan.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/update_dat.sh ${PREFIX}/sbin/update_dat
	${INSTALL_MAN} ${WRKSRC}/uvscan.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_SCRIPT} ${WRKSRC}/uvscan ${UVSCANDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/uvscan.sh ${PREFIX}/bin/uvscan
	${INSTALL_DATA} ${WRKSRC}/liblnxfv.so.4 ${UVSCANDIR}
	${LN} -s liblnxfv.so.4 ${UVSCANDIR}/liblnxfv.so
	for file in license.dat messages.dat; do			\
		${INSTALL_DATA} ${WRKSRC}/$${file} ${UVSCANDIR};	\
	done
	${INSTALL_DATA_DIR} ${EGDATDIR}
	for file in ${DATFILES}; do					\
		if [ -f ${WRKSRC}/$${file} ]; then			\
			${INSTALL_DATA} ${WRKSRC}/$${file} ${EGDATDIR};	\
		fi;							\
	done
	${INSTALL_DATA_DIR} ${DOCDIR}
	for file in contact.txt e5100upg.pdf license.txt ; do		\
		${INSTALL_DATA} ${WRKSRC}/$${file} ${DOCDIR};		\
	done

.include "../../mk/bsd.pkg.mk"
