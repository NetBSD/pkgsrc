# $NetBSD: Makefile,v 1.4 2005/06/17 03:50:36 jlam Exp $
#

DISTNAME=		RAIDAdmin1.3archive
PKGNAME=		xraidadmin-1.3
CATEGORIES=		sysutils
MASTER_SITES=		http://download.info.apple.com/Mac_OS_X/061-1159.20040318.Pplkf/
EXTRACT_SUFX=		.zip

MAINTAINER=		jschauma@NetBSD.org
HOMEPAGE=		http://www.apple.com/support/downloads/xserveraidadmintools.html
COMMENT=		Tool to administer Apple's Xserve RAID

LICENSE=		apple-admin

RESTRICTED=		"Redistribution not permitted"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=  	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=  	${RESTRICTED}

WRKSRC=			${WRKDIR}/RAID\ Admin\ 1.3

NO_BUILD=		# defined
USE_JAVA=		run
PKG_JVMS_ACCEPTED=	sun-jdk13 sun-jdk14
INSTALLATION_DIRS=	bin

do-configure:
	${SED} -e 's|@SH@|${SH}|' -e 's|@PKG_JAVA_HOME@|${PKG_JAVA_HOME}|' \
		-e 's|@PREFIX@|${PREFIX}|' ${FILESDIR}/xraidadmin.in >	   \
		${WRKSRC}/xraidadmin

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/xraidadmin
	${INSTALL_DATA} ${WRKSRC}/RAID_Admin.jar ${PREFIX}/libexec/xraidadmin/RAID_Admin.jar
	${INSTALL_SCRIPT} ${WRKSRC}/xraidadmin ${PREFIX}/bin/xraidadmin

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
