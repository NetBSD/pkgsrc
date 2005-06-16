# $NetBSD: Makefile,v 1.18 2005/06/16 06:57:47 jlam Exp $
#

DISTNAME=		pvs-${VERSION}
PKGREVISION=		2
CATEGORIES=		devel lang
MASTER_SITES=		ftp://pvs.csl.sri.com/pub/pvs/pvs${VERSION}/ \
			ftp://ftp.cs.york.ac.uk/pub/pvs/pvs${VERSION}/ \
			ftp://ftp.informatik.uni-ulm.de/pub/KI/pvs/pvs${VERSION}/
EXTRACT_SUFX=		.tgz
DISTFILES=		${DISTNAME}-${MAINFILEEXT}${EXTRACT_SUFX} \
			pvs-${VERSION}-system${EXTRACT_SUFX} \
			pvs-${VERSION}-emacs19${EXTRACT_SUFX} \
			pvs-${VERSION}-libraries${EXTRACT_SUFX}

MAINTAINER=		jschauma@NetBSD.org
HOMEPAGE=		http://pvs.csl.sri.com/
COMMENT=		The PVS Specification and Verification System

DEPENDS+=		teTeX>=1.0.7:../../print/teTeX
DEPENDS+=		tk>=8.0:../../x11/tk

WRKSRC=			${WRKDIR}
VERSION=		3.1
NO_BUILD=		# defined
CHECK_SHLIBS=		NO
SHLIB_HANDLING=		NO
INFO_DIR=		pvs/doc/release-notes
INFO_FILES=		pvs-release-notes.info

LICENSE=        	pvs-license
# not quite sure about this, but to be on the safe side:
RESTRICTED=     	"Redistribution not permitted - see ${HOMEPAGE}license.html"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=  	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=  	${RESTRICTED}

ONLY_FOR_PLATFORM=	NetBSD-1.6*-* NetBSD-[2-9]*-* Linux-*-* SunOS-*-*

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "sparc") || ${OPSYS} != "SunOS"
MAINFILEEXT=		linux
.else
MAINFILEEXT=		solaris
.endif

.if ${OPSYS} == "NetBSD"
MESSAGE_SRC=		${FILESDIR}/MESSAGE
.endif

INSTALLATION_DIRS=	bin

post-patch:
	${SED} -e "s|@PREFIX@|${PREFIX}|" ${WRKSRC}/pvs > \
		${WRKSRC}/pvs.tmp
	${MV} ${WRKSRC}/pvs.tmp ${WRKSRC}/pvs
	${RM} ${WRKSRC}/pvs.orig
	${RM} ${WRKSRC}/doc/release-notes/pvs-release-notes.info.orig

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pvs ${PREFIX}/bin/pvs
	${INSTALL_PROGRAM_DIR} ${PREFIX}/pvs
	cd ${WRKSRC} && ${PAX} -s ,^./[.].*,, -rw . ${PREFIX}/pvs
	${CHMOD} 755 ${PREFIX}/pvs/pvs

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
