# $NetBSD: Makefile,v 1.1.1.1 2002/12/07 19:58:57 ad Exp $

DISTNAME=		raidmgt
PKGNAME=		raidutil-3.31
WRKSRC=			${WRKDIR}
CATEGORIES=		sysutils
MASTER_SITES=		# empty
EXTRACT_SUFX=		.tgz

MAINTAINER=		ad@netbsd.org
HOMEPAGE=		http://opensource.adaptec.com/
COMMENT=		DPT/Adaptec Storage Management software (raidutil)

# Should work on other platforms, not yet tested.
ONLY_FOR_PLATFORM=	NetBSD-*-i386

RESTRICTED=		"Redistribution not permitted"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

CHECK_SHLIBS=		NO
NO_CONFIGURE=		# defined
INTERACTIVE_STAGE=	fetch

DOWNLOAD=		http://mbserver.adaptec.com/index.php?bn=linux_downloads

_FETCH_MESSAGE= \
	${ECHO} "================================================================="; \
	${ECHO} "  raidutil and dpteng source (raidmgt.tgz) must be fetched"; \
	${ECHO} "  into ${DISTDIR} from"; \
	${ECHO} "  ${DOWNLOAD}."; \
	${ECHO} "================================================================="

post-patch:
	${SED}	-e "s,@SBINDIR@,${PREFIX}/sbin,g"			\
		${WRKDIR}/dpteng/makefile > ${WRKDIR}/dpteng/makefile.tmp
	${MV} ${WRKDIR}/dpteng/makefile.tmp ${WRKDIR}/dpteng/makefile
	${SED}	-e "s,@SBINDIR@,${PREFIX}/sbin,g"			\
		${WRKDIR}/dptutil/makefile > ${WRKDIR}/dptutil/makefile.tmp
	${MV} ${WRKDIR}/dptutil/makefile.tmp ${WRKDIR}/dptutil/makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dpteng/dpteng ${PREFIX}/sbin/dpteng
	${INSTALL_PROGRAM} ${WRKSRC}/dptutil/raidutil ${PREFIX}/sbin/nbraidutil

.include "../../mk/bsd.pkg.mk"
