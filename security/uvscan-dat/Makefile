# $NetBSD: Makefile,v 1.23 2001/11/22 12:27:16 martti Exp $
#

DISTNAME=		dat-4172
PKGNAME=		uvscan-${DISTNAME}
CATEGORIES=		security
MASTER_SITES=		http://download.nai.com/products/datfiles/4.x/nai/ \
			http://gd.tuwien.ac.at/pc/nai/antivirus/datfiles/4.x/ \
			ftp://ftp.tuwien.ac.at/pc/nai/antivirus/datfiles/4.x/
EXTRACT_SUFX=		.tar

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.nai.com/asp_set/download/dats/mcafee_4x.asp
COMMENT=		AntiVirus DAT file for uvscan

NO_BUILD=		YES

RESTRICTED=		"restricted to the license terms set for VirusScan"
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

WRKSRC=			${WRKDIR}
DOCDIR=			${PREFIX}/share/doc/uvscan
DATDIR=			${PREFIX}/share/uvscan
DATFILES=		clean.dat internet.dat names.dat scan.dat readme.txt
DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

FILES_SUBST=		PREFIX=${PREFIX}
FILES_SUBST+=		DATFILES=${DATFILES:Q}
FILES_SUBST+=		CAT=${CAT:Q}
FILES_SUBST+=		CMP=${CMP:Q}
FILES_SUBST+=		CP=${CP:Q}
FILES_SUBST+=		MKDIR=${MKDIR:Q}
FILES_SUBST+=		RM=${RM:Q}
FILES_SUBST+=		RMDIR=${RMDIR:Q}
FILES_SUBST+=		TRUE=${TRUE:Q}
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

do-configure:
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/update_dat > ${WRKDIR}/update_dat

pre-install:
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/update_dat ${PREFIX}/sbin

	${INSTALL_DATA_DIR} ${DATDIR}
	cd ${WRKSRC};							\
	for file in ${DATFILES}; do					\
		${INSTALL_DATA} $${file} ${DATDIR};			\
	done

	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC};							\
	for file in reseller.txt packing.lst; do			\
		${INSTALL_DATA} $${file} ${DOCDIR};			\
	done

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
