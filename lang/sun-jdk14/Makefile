# $NetBSD: Makefile,v 1.1.2.2 2002/06/23 18:50:47 jlam Exp $

# MASTER_SITES is very special, and must end in "=":
DISTNAME=	j2sdk-1_4_0-linux-i386
PKGNAME=	sun-jdk-1.4.0
CATEGORIES=     lang
MASTER_SITES=	http://java.sun.com/Download4?config-file=j2sdk-1_4_0.config&platform=linux-i386&protocol=HTTP+download&download-name=
EXTRACT_SUFX=	.bin

MAINTAINER=	jschauma@netbsd.org
HOMEPAGE=	http://java.sun.com/
COMMENT=	Sun's Java(tm) Development Kit 1.4.0

DEPENDS=	sun-jre-1.4.0:../../lang/sun-jre14

CONFLICTS=	jdk-[0-9]* blackdown-j* sun-jdk-1.3*

FETCH_BEFORE_ARGS=-o ${DISTNAME}${EXTRACT_SUFX}
EXTRACT_CMD=	${ECHO} yes | ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} >/dev/null
WRKSRC=		${WRKDIR}/j2sdk1.4.0

LICENSE=	jdk13-license
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

ONLY_FOR_PLATFORM= NetBSD-1.5Z[A-Z]-i386 NetBSD-1.[6-9]*-i386 Linux-*-i[3-6]86
LDD=		${TRUE}

post-fetch:
	@${CHMOD} +x ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

post-extract:
	@${RM} -rf ${WRKSRC}/jre ${WRKSRC}/bin/java

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -print | ${XARGS} ${RM} -f

# This is ugly.  The chown should happen after copying, ot tar should have
# a way to override permissions.
do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}
	${CHOWN} -hR ${BINOWN}:${BINGRP} ${WRKSRC}
	${GTAR} -C ${WRKSRC} -cf- . | ${GTAR} -C ${PREFIX} -xpf-

.include "../../mk/bsd.pkg.mk"

# These need to be after bsd.pkg.mk 

.if ${OPSYS} == "Linux"
# No patches on linux
PATCHDIR=	${WRKDIR}/.patches
pre-patch:
	${MKDIR} ${PATCHDIR}
.endif

PREFIX:=	${JDK_HOME}
