# $NetBSD: Makefile,v 1.18 2002/03/01 01:58:36 abs Exp $
#

# MASTER_SITES is very special, and must end in "=":
DISTNAME=	j2re-1_3_1_01-linux-i386
PKGNAME=	sun-jre-1.3.1.0.1
CATEGORIES=     lang
MASTER_SITES=	http://java.sun.com/Download4?config-file=j2re-1_3_1_01.config&platform=linux-i386&protocol=HTTP+download&download-name=
EXTRACT_SUFX=	.bin

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://java.sun.com/
COMMENT=	Sun's Java(tm) Runtime Environment 1.3.1

CONFLICTS=	jdk-[0-9]* blackdown-j*

FETCH_BEFORE_ARGS=-o ${DISTNAME}${EXTRACT_SUFX}
EXTRACT_CMD=	${ECHO} yes | ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} >/dev/null
WRKSRC=		${WRKDIR}/jre1.3.1_01

LICENSE=	jdk13-license
RESTRICTED=	"Redistribution of repackaged binaries not permitted"
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}

.include "../../mk/bsd.prefs.mk"

# Needs to be after bsd.prefs.mk
.if ${OPSYS} != "Linux"
DEPENDS+=	suse_compat-[0-9]*:../../emulators/suse_compat
DEPENDS+=	suse_x11-[0-9]*:../../emulators/suse_x11
.endif

.if !defined(JDK_HOME)
JDK_HOME:=	${LOCALBASE}/java
.endif

# since we change PREFIX:
NO_MTREE=	yes

ONLY_FOR_PLATFORM= NetBSD-*-i386 Linux-*-i[3-6]86
LDD=		${TRUE}

post-fetch:
	@${CHMOD} +x ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -print | ${XARGS} ${RM} -f

do-build:
	${SED} -e "s,@PREFIX@,${PREFIX}," ${FILESDIR}/wrap.sh >${WRKDIR}/java

# This is ugly.  The chown should happen after copying, or tar should have
# a way to override permissions.
do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX} ${PREFIX}/jre
	${INSTALL_PROGRAM_DIR} ${PREFIX} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/java ${PREFIX}/bin/java
	${CHOWN} -hR ${BINOWN}:${BINGRP} ${WRKSRC}
	${GTAR} -C ${WRKSRC} -cf- . | ${GTAR} -C ${PREFIX}/jre -xpf-

.include "../../mk/bsd.pkg.mk"

# These need to be after bsd.pkg.mk 

.if ${OPSYS} == "Linux"
# No patches on linux
PATCHDIR=	${WRKDIR}/.patches
pre-patch:
	${MKDIR} ${PATCHDIR}
.endif

PREFIX:=	${JDK_HOME}
