# $NetBSD: Makefile,v 1.9 2002/08/07 17:28:56 jschauma Exp $
#

DISTNAME=	unix_jb35foundation
PKGNAME=	jbuilder-jit-1.2.15
PKGREVISION=	1
CATEGORIES=     lang
MASTER_SITES=	http://ftp.cdut.edu.cn/pub2/linux/develop/jbuilder/ \
				http://python.planetmirror.com/ftp/jbuilder/foundation/3.5/linux/ \
				http://planetmirror.com.au/ftp/jbuilder/foundation/3.5/linux/ \
				http://www.au.horde.org/pub/jbuilder/foundation/3.5/linux/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.borland.com
COMMENT=	Just-In-Time compiler for Linux Java Virtual Machine

USE_JAVA=	run
PKG_JVM=	sun-jdk13 # works with both 1.2.2 and 1.3 JVMs
PLIST_SUBST+=	JAVADIR=${JAVA_HOME:C|${PREFIX}/||}

WRKSRC=		${WRKDIR}/javacomp-1.2.15
EXTRACT_ELEMENTS=	LinuxJIT/javacomp-1.2.15.tar.gz

LICENSE=	single-user-license
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
		${JAVA_HOME}/lib/i386/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/jbuilder-jit
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${PREFIX}/share/doc/jbuilder-jit/README.javacomp
	${INSTALL_DATA} ${WRKSRC}/LICENSE.TXT ${PREFIX}/share/doc/jbuilder-jit/LICENSE.javacomp

.include "../../mk/bsd.pkg.mk"

# This needs to be after bsd.pkg.mk 
PREFIX:=	${JDK_HOME}
