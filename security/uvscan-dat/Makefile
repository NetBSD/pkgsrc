# $NetBSD: Makefile,v 1.24 2001/12/13 06:42:48 jlam Exp $
#

DISTNAME=		dat-4176
PKGNAME=		uvscan-${DISTNAME}
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.nai.com/pub/datfiles/english/ \
			ftp://ftpeur.nai.com/pub/datfiles/english/ \
			ftp://ftpde.nai.com/pub/datfiles/english/ \
			http://gd.tuwien.ac.at/pc/nai/antivirus/datfiles/4.x/ \
			ftp://ftp.tuwien.ac.at/pc/nai/antivirus/datfiles/4.x/
EXTRACT_SUFX=		.tar

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.mcafeeb2b.com/naicommon/download/dats/mcafee_4x.asp
COMMENT=		AntiVirus DAT file for uvscan

USE_BUILDLINK_ONLY=	YES
NO_BUILD=		YES

RESTRICTED=		"restricted to the license terms set for VirusScan"
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

WRKSRC=			${WRKDIR}
DOCDIR=			${PREFIX}/share/doc/uvscan
DATDIR=			${PREFIX}/share/uvscan
UVSCANDIR=		${PREFIX}/libexec/uvscan
DATFILES=		clean.dat internet.dat names.dat scan.dat readme.txt

SUPPORT_FILES=		${DATDIR}/clean.dat ${UVSCANDIR}/clean.dat
SUPPORT_FILES+=		${DATDIR}/internet.dat ${UVSCANDIR}/internet.dat
SUPPORT_FILES+=		${DATDIR}/names.dat ${UVSCANDIR}/names.dat
SUPPORT_FILES+=		${DATDIR}/scan.dat ${UVSCANDIR}/scan.dat
SUPPORT_FILES+=		${DATDIR}/readme.txt ${UVSCANDIR}/readme.txt
OWN_DIRS=		${UVSCANDIR}

DEINSTALL_EXTRA_TMPL=	${.CURDIR}/DEINSTALL
FILES_SUBST+=		DATFILES=${DATFILES:Q}

do-configure:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/update_dat > ${WRKDIR}/update_dat

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/update_dat ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${DATDIR}
	for file in ${DATFILES}; do					\
		${INSTALL_DATA} ${WRKSRC}/$${file} ${DATDIR};		\
	done
	${INSTALL_DATA_DIR} ${DOCDIR}
	for file in reseller.txt packing.lst; do			\
		${INSTALL_DATA} ${WRKSRC}/$${file} ${DOCDIR};		\
	done

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
