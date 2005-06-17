# $NetBSD: Makefile,v 1.26 2005/06/17 03:50:33 jlam Exp $

DISTNAME=		vlnx424e
PKGNAME=		uvscan-4.24.1
CATEGORIES=		security
MASTER_SITES=		http://download.nai.com/products/evaluation/virusscan/english/cmdline/linux/version_4.24/intel/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.nai.com/us/products/mcafee/antivirus/desktop/vs_unix.htm
COMMENT=		Evaluation version of a DOS/Windows file virus scanner

CONFLICTS=		uvscan-dat-[0-9]*

DEPENDS+=		suse_compat>=6.1:../../emulators/${SUSE_DIR_PREFIX}_compat

ONLY_FOR_PLATFORM=	NetBSD-*-i386
CHECK_SHLIBS=		NO

WRKSRC=			${WRKDIR}
LICENSE=		shareware
RESTRICTED=		"restrictive 30 day evaluation license"
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

DOCDIR=			${PREFIX}/share/doc/uvscan
DATDIR=			${PREFIX}/share/uvscan
UVSCANDIR=		${PREFIX}/libexec/uvscan
DATFILES=		clean.dat internet.dat names.dat scan.dat pkgdesc.ini

USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL

FILES_SUBST+=		UVSCANDIR=${UVSCANDIR:Q}
FILES_SUBST+=		DATFILES=${DATFILES:Q}

SUPPORT_FILES=		${DATDIR}/clean.dat ${UVSCANDIR}/clean.dat
SUPPORT_FILES+=		${DATDIR}/names.dat ${UVSCANDIR}/names.dat
SUPPORT_FILES+=		${DATDIR}/scan.dat ${UVSCANDIR}/scan.dat
OWN_DIRS=		${UVSCANDIR}

INSTALLATION_DIRS=	bin man/man1 sbin

do-build:
	@${SED}	${FILES_SUBST_SED}					\
		${FILESDIR}/update_dat.sh > ${WRKDIR}/update_dat

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/update_dat ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/uvscan.1 ${PREFIX}/man/man1

	${INSTALL_PROGRAM_DIR} ${UVSCANDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/uvscan ${UVSCANDIR}
	${RM} -f ${PREFIX}/bin/uvscan
	${LN} -sf ../${UVSCANDIR:S/${PREFIX}\///}/uvscan ${PREFIX}/bin/uvscan
	${INSTALL_DATA} ${WRKSRC}/liblnxfv.so.4 ${UVSCANDIR}
	${RM} -f ${UVSCANDIR}/liblnxfv.so
	${LN} -s liblnxfv.so.4 ${UVSCANDIR}/liblnxfv.so
	for file in liblnxfv.so.4 liblnxfv.so; do			\
		${RM} -f ${PREFIX}/emul/linux/usr/local/lib/$${file};	\
		${LN} -s ${UVSCANDIR}/$${file}				\
			${PREFIX}/emul/linux/usr/local/lib;		\
	done
	for file in license.dat messages.dat; do			\
		${INSTALL_DATA} ${WRKSRC}/$${file} ${UVSCANDIR};	\
	done
	${INSTALL_DATA_DIR} ${DATDIR}
	for file in ${DATFILES}; do					\
		if [ -f ${WRKSRC}/$${file} ]; then			\
			${INSTALL_DATA} ${WRKSRC}/$${file} ${DATDIR};	\
		fi;							\
	done
	${INSTALL_DATA_DIR} ${DOCDIR}
	for file in contact.txt license.txt ; do			\
		${INSTALL_DATA} ${WRKSRC}/$${file} ${DOCDIR};		\
	done

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
