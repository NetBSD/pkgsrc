# $NetBSD: Makefile,v 1.14 2002/06/30 15:01:48 schmonz Exp $

# MASTER_SITES is very special, and must end in "=":
DISTNAME=	j2sdk-1_3_1_02-linux-i386
PKGNAME=	sun-jdk-1.3.1.0.2
CATEGORIES=     lang
MASTER_SITES=	http://java.sun.com/Download4?config-file=j2sdk-1_3_1_02.config&platform=linux-i386&protocol=HTTP+download&download-name=
EXTRACT_SUFX=	.bin

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://java.sun.com/
COMMENT=	Sun's Java(tm) Development Kit 1.3.1

DEPENDS=	sun-jre-1.3.1.0.2:../../lang/sun-jre13

CONFLICTS=	jdk-[0-9]* blackdown-j*

FETCH_BEFORE_ARGS=-o ${DISTNAME}${EXTRACT_SUFX}
EXTRACT_CMD=	${ECHO} yes | ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} >/dev/null
WRKSRC=		${WRKDIR}/jdk1.3.1_02

LICENSE=	jdk13-license
RESTRICTED=	"Redistribution of repackaged binaries not permitted"
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
DISTFILES=	# empty
NO_PATCH=	# defined
NO_CONFIGURE=	# defined
PLIST_SRC=	${PKGDIR}/PLIST.Darwin
.endif

.if !defined(JDK_HOME)
JDK_HOME:=	${LOCALBASE}/java
.endif

NO_BUILD=	yes
# since we change PREFIX:
NO_MTREE=	yes

ONLY_FOR_PLATFORM= NetBSD-*-i386 Linux-*-i[3-6]86 Darwin-*-*
LDD=		${TRUE}

post-fetch:
.	if ${OPSYS} != "Darwin"
	@${CHMOD} +x ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
.	endif

post-extract:
	@${RM} -rf ${WRKSRC}/jre ${WRKSRC}/bin/java

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -print | ${XARGS} ${RM} -f

# This is ugly.  The chown should happen after copying, ot tar should have
# a way to override permissions.
do-install:
.	if ${OPSYS} == "Darwin"
	@${ECHO_MSG} "Darwin ships with a JDK based on Sun's 1.3.1 release."
.	else
	${INSTALL_PROGRAM_DIR} ${PREFIX}
	${CHOWN} -hR ${BINOWN}:${BINGRP} ${WRKSRC}
	${GTAR} -C ${WRKSRC} -cf- . | ${GTAR} -C ${PREFIX} -xpf-
.	endif

.include "../../mk/bsd.pkg.mk"

# These need to be after bsd.pkg.mk 

.if ${OPSYS} == "Linux"
# No patches on linux
PATCHDIR=	${WRKDIR}/.patches
pre-patch:
	${MKDIR} ${PATCHDIR}
.endif

PREFIX:=	${JDK_HOME}
