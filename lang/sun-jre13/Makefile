# $NetBSD: Makefile,v 1.1.1.1 2000/11/18 00:36:55 tv Exp $
#

# MASTER_SITES is very special, and must end in "=":
DISTNAME=	j2sdk-1_3_0-linux
PKGNAME=	sun-jre-1.3.0
CATEGORIES=     lang
MASTER_SITES=	http://java.sun.com/Download4?config-file=j2sdk-1_3_0-linux.config&platform=targzsh&protocol=HTTP+download&download-name=
EXTRACT_SUFX=	.bin

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://java.sun.com/

DEPENDS=	suse_x11-*:../../emulators/suse_x11

CONFLICTS=	jdk-* blackdown-j*

FETCH_BEFORE_ARGS=-o ${DISTNAME}${EXTRACT_SUFX}
EXTRACT_CMD=	${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
WRKSRC=		${WRKDIR}/jdk1.3/jre

IS_INTERACTIVE=	yes
RESTRICTED=	"Redistribution of repackaged binaries not permitted"
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}

.include "../../mk/bsd.prefs.mk"

.if !defined(JDK_HOME)
JDK_HOME:=	${LOCALBASE}/java
.endif

NO_BUILD=	yes
# since we change PREFIX:
NO_MTREE=	yes

ONLY_FOR_PLATFORM= NetBSD-*-i386
LDD=		${TRUE}

post-fetch:
	@${CHMOD} +x ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -print | xargs ${RM} -f

# This is ugly.  The chown should happen after copying, ot tar should have
# a way to override permissions.
do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX} ${PREFIX}/jre
	${CHOWN} -hR ${BINOWN}:${BINGRP} ${WRKSRC}
	${GTAR} -C ${WRKSRC} -cf- . | ${GTAR} -C ${PREFIX}/jre -xpf-

.include "../../mk/bsd.pkg.mk"

# This needs to be after bsd.pkg.mk 
PREFIX:=	${JDK_HOME}
