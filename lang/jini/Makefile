# $NetBSD: Makefile,v 1.3 2002/07/13 15:46:59 jschauma Exp $
#

DISTNAME=	jini-1_2_1-src
PKGNAME=	jini-1.2.1
CATEGORIES=     lang
MASTER_SITES=   # empty
EXTRACT_SUFX=   .zip

MAINTAINER=     jschauma@netbsd.org
HOMEPAGE=       http://www.sun.com/jini/
COMMENT=	Suns Jini(tm) Technology Starter Kit

# depends on Rev 1.39 of sys/compat/linux/common/linux_socket.c
# comment out if you have a kernel built using that revision
ONLY_FOR_PLATFORM=	NetBSD-1.5Z[D-Z]-* NetBSD-1.[6-9]*-* Linux-*-*

INTERACTIVE_STAGE=fetch
LICENSE=	scsl3-jini-tsa-1.0-license
RESTRICTED= "Redistribution of repackaged binaries not permitted"
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=  ${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=  ${RESTRICTED}

USE_JAVA=	yes
PKG_JVM=	sun-jdk

.include "../../mk/bsd.prefs.mk"

.if !defined(JINI_HOME)
JINI_HOME:=	${LOCALBASE}/jini
.endif
MESSAGE_SUBST+=	JINI_HOME=${JINI_HOME}

NO_BUILD=	yes

DOWNLOAD=	http://wwws.sun.com/software/communitysource/jini/download.html
WRKSRC=		${WRKDIR}/jini1_2_1

_FETCH_MESSAGE=	\
	${ECHO} "======================================================================"; \
	${ECHO} ; \
	${ECHO} " The file ${DISTNAME}${EXTRACT_SUFX} containing the Jini(TM)"; \
	${ECHO} " Technology Starter Kit must be fetched into ${DISTDIR} from "; \
	${ECHO} " ${DOWNLOAD}."; \
	${ECHO} ; \
	${ECHO} "======================================================================"

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/jini
	${CHOWN} -hR ${BINOWN}:${BINGRP} ${WRKSRC}
	${GTAR} -C ${WRKSRC} -cf- . | ${GTAR} -C ${PREFIX}/jini -xpf-

cleandir: clean
	${RM} -fr ${JINI_HOME}

.include "../../mk/bsd.pkg.mk"
