# $NetBSD: Makefile,v 1.4 2001/05/19 03:56:36 jlam Exp $
#

DISTNAME=       blackdown-jdk-1.3.0.nb2
CATEGORIES=     lang
MASTER_SITES+=  http://linuxppc.org/software/java/dl/jdk130/
MASTER_SITES+=  ftp://ftp.netbsd.org/pub/NetBSD/misc/manu/
DISTFILES+=     j2sdk-1.3.0beta-b02-linux-ppc.tar.bz2 powerpc-jdk-addon.tgz

MAINTAINER=     manu@netbsd.org
HOMEPAGE=       http://linuxppc.org/software/java/j2sdk_files.html
COMMENT=        Blackdown's Java(tm) Development Kit 1.3.0

DEPENDS+=	linuxppc_lib>=2000.4.2:../../emulators/linuxppc_lib

CONFLICTS=      jdk-* blackdown-j*

WRKSRC=		${WRKDIR}/j2sdk1.3

RESTRICTED= "Redistribution of repackaged binaries not permitted"
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP= ${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP= ${RESTRICTED}

.include "../../mk/bsd.prefs.mk"

.if !defined(JDK_HOME)
JDK_HOME:=  ${LOCALBASE}/java
.endif

NO_BUILD=   yes
# since we change PREFIX:
NO_MTREE=   yes

ONLY_FOR_PLATFORM= NetBSD-*-powerpc

post-fetch:
	@cd ${DISTDIR} && ${CHMOD} +x ${DISTFILES}

post-patch:
	@${CP} ${WRKDIR}/libhpi.so \
	    ${WRKSRC}/jre/lib/ppc/native_threads/libhpi.so
	@${FIND} ${WRKSRC} -name '*.orig' -print | ${XARGS} ${RM} -f
	@${FIND} ${WRKSRC} -name '*.1.gz' -print | ${XARGS} ${GUNZIP_CMD}

# This is ugly.  The chown should happen after copying, ot tar should have
# a way to override permissions.
do-install:
	${INSTALL_PROGRAM_DIR} ${JDK_HOME}
	${CHOWN} -hR ${BINOWN}:${BINGRP} ${WRKSRC}
	${CHMOD} -R uog+r ${WRKSRC}
	${FIND} ${WRKSRC}/bin ${WRKSRC}/jre/bin -type f | ${XARGS} ${CHMOD} uog+rx
	${FIND} ${WRKSRC} -type d | ${XARGS} ${CHMOD} uog+rx
	${GTAR} -C ${WRKSRC} -cf- . | ${GTAR} -C ${JDK_HOME} -xpf-

.include "../../mk/bsd.pkg.mk"
