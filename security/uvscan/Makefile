# $NetBSD: Makefile,v 1.11 2001/12/13 06:53:16 jlam Exp $

DISTNAME=		vlnx416e
PKGNAME=		uvscan-4.16.0
CATEGORIES=		security
MASTER_SITES=		http://download.nai.com/products/evaluation/virusscan/english/cmdline/linux/version_4.16/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.mcafeeb2b.com/products/virusscan/default.asp
COMMENT=		evaluation version of a DOS/Windows file virus scanner

DEPENDS+=		suse_compat>=6.1:../../emulators/suse_base
DEPENDS+=		uvscan-dat>=4171:../../security/uvscan-dat

ONLY_FOR_PLATFORM=	NetBSD-*-i386
NO_BUILD=		YES
CHECK_SHLIBS=		NO

LICENSE=		shareware
RESTRICTED=		"restrictive 30 day evaluation license"
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

WRKSRC=			${WRKDIR}
DOCDIR=			${PREFIX}/share/doc/uvscan
UVSCANDIR=		${PREFIX}/libexec/uvscan

do-configure:
	${SED}	-e "s|@PREFIX@|${PREFIX}|g"				\
		${FILESDIR}/uvscan.sh > ${WRKDIR}/uvscan.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/uvscan.sh ${PREFIX}/bin/uvscan
	${INSTALL_MAN} ${WRKSRC}/uvscan.1 ${PREFIX}/man/man1

	${INSTALL_PROGRAM_DIR} ${UVSCANDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/uvscan ${UVSCANDIR}
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
	${INSTALL_DATA_DIR} ${DOCDIR}
	for file in contact.txt license.txt unxadmin.pdf; do		\
		${INSTALL_DATA} ${WRKSRC}/$${file} ${DOCDIR};		\
	done

.include "../../mk/bsd.pkg.mk"
