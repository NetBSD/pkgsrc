# $NetBSD: Makefile,v 1.21 2002/06/30 15:01:49 schmonz Exp $

# MASTER_SITES is very special, and must end in "=":
DISTNAME=	j2re-1_3_1_02-linux-i386
PKGNAME=	sun-jre-1.3.1.0.2
CATEGORIES=     lang
MASTER_SITES=	http://java.sun.com/Download4?config-file=j2re-1_3_1_02.config&platform=linux-i386&protocol=HTTP+download&download-name=
EXTRACT_SUFX=	.bin

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://java.sun.com/
COMMENT=	Sun's Java(tm) Runtime Environment 1.3.1

CONFLICTS=	jdk-[0-9]* blackdown-j*

FETCH_BEFORE_ARGS=-o ${DISTNAME}${EXTRACT_SUFX}
EXTRACT_CMD=	${ECHO} yes | ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} >/dev/null
WRKSRC=		${WRKDIR}/jre1.3.1_02

LICENSE=	jdk13-license
RESTRICTED=	"Redistribution of repackaged binaries not permitted"
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}

.include "../../mk/bsd.prefs.mk"

# Needs to be after bsd.prefs.mk
.if ${OPSYS} == "NetBSD"
DEPENDS+=	suse_compat-[0-9]*:../../emulators/${SUSE_DIR_PREFIX}_compat
DEPENDS+=	suse_x11-[0-9]*:../../emulators/${SUSE_DIR_PREFIX}_x11
.endif

.if ${OPSYS} == "Darwin"
DISTFILES=	# empty
NO_PATCH=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined
PLIST_SRC=	${PKGDIR}/PLIST.Darwin
.endif

.if !defined(JDK_HOME)
JDK_HOME:=	${LOCALBASE}/java
.endif

# since we change PREFIX:
NO_MTREE=	yes

ONLY_FOR_PLATFORM= NetBSD-*-i386 Linux-*-i[3-6]86 Darwin-*-*
LDD=		${TRUE}

post-fetch:
.	if ${OPSYS} != "Darwin"
	@${CHMOD} +x ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
.	endif

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -print | ${XARGS} ${RM} -f

do-build:
	${SED} -e "s,@PREFIX@,${PREFIX}," ${FILESDIR}/wrap.sh >${WRKDIR}/java

# This is ugly.  The chown should happen after copying, or tar should have
# a way to override permissions.
do-install:
.	if ${OPSYS} == "Darwin"
	@${ECHO_MSG} "Darwin ships with a JRE based on Sun's 1.3.1 release."
.	else
	${INSTALL_PROGRAM_DIR} ${PREFIX} ${PREFIX}/jre
	${INSTALL_PROGRAM_DIR} ${PREFIX} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/java ${PREFIX}/bin/java
	${CHOWN} -hR ${BINOWN}:${BINGRP} ${WRKSRC}
	${GTAR} -C ${WRKSRC} -cf- . | ${GTAR} -C ${PREFIX}/jre -xpf-
.	endif

.include "../../emulators/suse_linux/Makefile.application"

# These need to be after bsd.pkg.mk 

.if ${OPSYS} == "Linux"
# No patches on linux
PATCHDIR=	${WRKDIR}/.patches
pre-patch:
	${MKDIR} ${PATCHDIR}
.endif

PREFIX:=	${JDK_HOME}
