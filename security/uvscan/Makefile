# $NetBSD: Makefile,v 1.10 2001/09/09 20:36:46 agc Exp $

DISTNAME=		vlnx414e
PKGNAME=		uvscan-4.14.0
CATEGORIES=		security
MASTER_SITES=		http://download.nai.com/products/evaluation/virusscan/english/unix/linux/v4.14.0/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.mcafeeb2b.com/products/virusscan/default.asp
COMMENT=		evaluation version of a DOS/Windows file virus scanner

DEPENDS+=		suse_compat>=6.1:../../emulators/suse_base
DEPENDS+=		uvscan-dat>=4129:../../security/uvscan-dat

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
	cd ${WRKSRC}; for file in uvscan liblnxfv.so; do		\
		${INSTALL_SCRIPT} $${file} ${UVSCANDIR};		\
	done
	${RM} -f ${PREFIX}/emul/linux/usr/local/lib/liblnxfv.so
	${LN} -s ${UVSCANDIR}/liblnxfv.so ${PREFIX}/emul/linux/usr/local/lib
	cd ${WRKSRC}; for file in license.dat messages.dat; do		\
		${INSTALL_DATA} $${file} ${UVSCANDIR};			\
	done

	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; for file in unxadmin.pdf license.txt; do		\
		${INSTALL_DATA} ${WRKSRC}/$${file} ${DOCDIR};		\
	done

.include "../../mk/bsd.pkg.mk"
