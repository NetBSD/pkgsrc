# $NetBSD: Makefile,v 1.1.1.1 2000/10/16 17:53:53 tv Exp $
#

DISTNAME=	j2sdk-1.2.2-FCS-linux-i386-glibc-2.1.3
PKGNAME=	blackdown-jdk-1.2.2
CATEGORIES=     lang
MASTER_SITES=	ftp://metalab.unc.edu/pub/linux/devel/lang/java/blackdown.org/${FTPSUBDIR}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.blackdown.org/

DEPENDS=	blackdown-jre-1.2.2:../../lang/blackdown-jre12

CONFLICTS=	jdk-*
WRKSRC=		${WRKDIR}/jdk1.2.2

RESTRICTED=	"Redistribution of repackaged binaries not permitted"
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}

# Blackdown tree subdirectory for this version
FTPSUBDIR=	JDK-1.2.2/i386/FCS

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
	${INSTALL_PROGRAM_DIR} ${PREFIX}
	${CHOWN} -hR ${BINOWN}:${BINGRP} ${WRKSRC}
	cd ${WRKSRC} && ${GTAR} -cf- [A-Zbdils]* \
		jre/lib/i386/libagent.so \
		jre/lib/i386/libdt_socket.so \
		jre/lib/i386/libjdwp.so \
		| ${GTAR} -C ${PREFIX} -xpf-

.include "../../mk/bsd.pkg.mk"

# This needs to be after bsd.pkg.mk 
PREFIX:=	${JDK_HOME}
