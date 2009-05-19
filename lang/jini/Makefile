# $NetBSD: Makefile,v 1.28 2009/05/19 08:59:19 wiz Exp $
#

DISTNAME=		jini-${SUN_VERSION}-src
PKGNAME=		jini-${VERSION}
PKGREVISION=		2
CATEGORIES=		lang java
MASTER_SITES=		# empty
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.sun.com/software/jini/
COMMENT=		Suns Jini(tm) Technology Starter Kit
LICENSE=		scsl3-jini-tsa-1.0-license

RESTRICTED=		Redistribution of repackaged binaries not permitted
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

ONLY_FOR_PLATFORM=	Darwin-*-* Linux-*-* NetBSD-1.[6-9]*-*
ONLY_FOR_PLATFORM+=	NetBSD-[2-9]*-*
# depends on Rev 1.39 of sys/compat/linux/common/linux_socket.c
ONLY_FOR_PLATFORM+=	NetBSD-1.5Z[D-Z]-*

INTERACTIVE_STAGE=	fetch

USE_TOOLS+=	pax

PKG_DESTDIR_SUPPORT=	destdir

WRKSRC=			${WRKDIR}/jini${SUN_VERSION}
VERSION=		1.2.1
SUN_VERSION=		${VERSION:C/\./_/g}_001
USE_JAVA=		run
PKG_JVMS_ACCEPTED=	sun-jdk13 sun-jdk14 jdk14

.include "../../mk/bsd.prefs.mk"

.if !defined(JINI_HOME)
JINI_HOME:=		${LOCALBASE}/jini
.endif
MESSAGE_SUBST+=		JINI_HOME=${JINI_HOME}

NO_BUILD=		yes

DOWNLOAD=		http://wwws.sun.com/software/communitysource/jini/download.html

FETCH_MESSAGE=	"The file ${DISTNAME}${EXTRACT_SUFX} containing the Jini(TM)"
FETCH_MESSAGE+=	"Technology Starter Kit must be fetched into ${DISTDIR} from"
FETCH_MESSAGE+=	${DOWNLOAD:Q}

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/jini
	${CHOWN} -hR ${BINOWN}:${BINGRP} ${WRKSRC}
	cd ${WRKSRC} && pax -rw . ${DESTDIR}${PREFIX}/jini

cleandir: clean
	${RM} -fr ${JINI_HOME}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
