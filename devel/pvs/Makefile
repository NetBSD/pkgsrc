# $NetBSD: Makefile,v 1.4 2003/01/04 22:00:08 jschauma Exp $
#

DISTNAME=		pvs-${VERSION}
PKGREVISION=		1
CATEGORIES=		devel lang
MASTER_SITES=		ftp://pvs.csl.sri.com/pub/pvs/pvs${VERSION}/ \
			ftp://ftp.cs.york.ac.uk/pub/pvs/pvs${VERSION}/ \
			ftp://ftp.informatik.uni-ulm.de/pub/KI/pvs/pvs${VERSION}/
EXTRACT_SUFX=		.tgz
DISTFILES=		${DISTNAME}-${MAINFILEEXT}${EXTRACT_SUFX} \
			pvs-3.0-system${EXTRACT_SUFX} \
			pvs-3.0-emacs19${EXTRACT_SUFX} \
			pvs-3.0-libraries${EXTRACT_SUFX}

MAINTAINER=		jschauma@netbsd.org
HOMEPAGE=		http://pvs.csl.sri.com/
COMMENT=		The PVS Specification and Verification System

DEPENDS+=		teTeX>=1.0.7:../../print/teTeX

VERSION=		3.0
WRKSRC=			${WRKDIR}
NO_BUILD=		# defined
CHECK_SHLIBS=		NO
SHLIB_HANDLING=		NO
USE_BUILDLINK2=		yes

LICENSE=        	pvs-license
# not quite sure about this, but to be on the safe side:
RESTRICTED=     	"Redistribution not permitted - see ${HOMEPAGE}license.html"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=  	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=  	${RESTRICTED}

ONLY_FOR_PLATFORM=	NetBSD-1.[6-9]*-* Linux-*-* SunOS-*-*

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "sparc") || ${OPSYS} != "SunOS"
MAINFILEEXT=		redhat5
.else
MAINFILEEXT=		solaris
.endif

.if ${OPSYS} == "NetBSD"
MESSAGE_SRC=		${FILESDIR}/MESSAGE
.endif

post-patch:
	${SED} -e "s|@PREFIX@|${PREFIX}|" ${WRKSRC}/pvs > \
		${WRKSRC}/pvs.tmp
	${MV} ${WRKSRC}/pvs.tmp ${WRKSRC}/pvs
	${RM} ${WRKSRC}/pvs.orig

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pvs ${PREFIX}/bin/pvs
	${INSTALL_PROGRAM_DIR} ${PREFIX}/pvs
	cd ${WRKSRC} && ${PAX} -s ,^./[.].*,, -rw . ${PREFIX}/pvs
	${CHMOD} 755 ${PREFIX}/pvs/pvs

.include "../../x11/tk/buildlink2.mk"
.include "../../mk/emacs.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
