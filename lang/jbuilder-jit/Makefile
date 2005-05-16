# $NetBSD: Makefile,v 1.21 2005/05/16 01:15:32 jlam Exp $
#

DISTNAME=	unix_jb35foundation
PKGNAME=	jbuilder-jit-1.2.15
PKGREVISION=	1
CATEGORIES=     lang java
MASTER_SITES=	http://ftp.cdut.edu.cn/pub2/linux/develop/jbuilder/ \
		http://python.planetmirror.com/ftp/jbuilder/foundation/3.5/linux/ \
		http://planetmirror.com.au/ftp/jbuilder/foundation/3.5/linux/ \
		http://www.au.horde.org/pub/jbuilder/foundation/3.5/linux/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.borland.com/
COMMENT=	Just-In-Time compiler for Linux Java Virtual Machine

WRKSRC=		${WRKDIR}/javacomp-1.2.15
USE_JAVA=	run
USE_JAVA2=	yes
PLIST_SUBST+=	JAVADIR=${PKG_JAVA_HOME:C|${PREFIX}/||}

EXTRACT_ELEMENTS=	LinuxJIT/javacomp-1.2.15.tar.gz

LICENSE=		single-user-license
RESTRICTED=		"Redistribution of binaries not permitted"
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
PKGSRC_USE_TOOLS+=	gtar

NO_BUILD=		yes

# this package is only for Sun 1.3 JVMs built for x86 Linux
ONLY_FOR_PLATFORM=	NetBSD-*-i386 Linux-*-i386
PKG_JVMS_ACCEPTED=	blackdown-jdk13

post-extract:
	@cd ${WRKDIR} && ${GTAR} -xzf ${EXTRACT_ELEMENTS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libjavacomp.so ${WRKSRC}/libjavacomp_g.so \
		${PKG_JAVA_HOME}/lib/i386/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/jbuilder-jit
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${PREFIX}/share/doc/jbuilder-jit/README.javacomp
	${INSTALL_DATA} ${WRKSRC}/LICENSE.TXT ${PREFIX}/share/doc/jbuilder-jit/LICENSE.javacomp

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
