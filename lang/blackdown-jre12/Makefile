# $NetBSD: Makefile,v 1.1.1.1 2000/10/16 17:53:21 tv Exp $
#

DISTNAME=	j2re-1.2.2-FCS-linux-i386-glibc-2.1.3
PKGNAME=	blackdown-jre-1.2.2
CATEGORIES=     lang
MASTER_SITES=	ftp://metalab.unc.edu/pub/linux/devel/lang/java/blackdown.org/${FTPSUBDIR}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.blackdown.org/

DEPENDS=	suse_x11-*:../../emulators/suse_x11

CONFLICTS=	jdk-*
WRKSRC=		${WRKDIR}/jre1.2.2

# Blackdown tree subdirectory for this version
FTPSUBDIR=	JDK-1.2.2/i386/FCS

RESTRICTED=	"Redistribution of repackaged binaries not permitted"
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

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -print | xargs ${RM} -f

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX} ${PREFIX}/jre
	${CHOWN} -hR ${BINOWN}:${BINGRP} ${WRKSRC}
	${GTAR} -C ${WRKSRC} -cf- . | ${GTAR} -C ${PREFIX}/jre -xpf-

.include "../../mk/bsd.pkg.mk"

# This needs to be after bsd.pkg.mk 
PREFIX:=	${JDK_HOME}
