# $NetBSD: Makefile,v 1.7 2002/07/31 19:33:20 schmonz Exp $
#

DISTNAME=	unix_jb35foundation
PKGNAME=	jbuilder-jit-1.2.15
CATEGORIES=     lang
MASTER_SITES=	http://www.vit.edu.tw/borland/JBuilder35Foundation/

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.inprise.com/jbuilder/foundation/linux.html
COMMENT=	Just-In-Time compiler for Linux Java Virtual Machine

USE_JAVA=	run
PKG_JVM=	sun-jdk13 # works with both 1.2.2 and 1.3 JVMs

WRKSRC=		${WRKDIR}/javacomp-1.2.15
EXTRACT_ELEMENTS= LinuxJIT/javacomp-1.2.15.tar.gz

RESTRICTED=	"Redistribution of binaries not permitted"
NO_BIN_ON_CDROM=${RESTRICTED}
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}

.include "../../mk/bsd.prefs.mk"

.if !defined(JDK_HOME)
JDK_HOME:=	${LOCALBASE}/java
.endif

NO_BUILD=	yes
# since we change PREFIX:
NO_MTREE=	yes

ONLY_FOR_PLATFORM= NetBSD-*-i386

post-extract:
	@cd ${WRKDIR} && ${GTAR} -xzf ${EXTRACT_ELEMENTS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libjavacomp.so ${WRKSRC}/libjavacomp_g.so \
		${PREFIX}/jre/lib/i386/
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${PREFIX}/jre/README.javacomp
	${INSTALL_DATA} ${WRKSRC}/LICENSE.TXT ${PREFIX}/jre/LICENSE.javacomp

.include "../../mk/bsd.pkg.mk"

# This needs to be after bsd.pkg.mk 
PREFIX:=	${JDK_HOME}
