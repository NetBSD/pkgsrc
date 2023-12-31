# $NetBSD: Makefile,v 1.9 2023/12/31 15:27:26 abs Exp $

DISTNAME=	Workbench-Build130
PKGNAME=	sql-workbench-130
CATEGORIES=	databases
MASTER_SITES=	http://www.sql-workbench.net/
EXTRACT_SUFX=	.zip

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://www.sql-workbench.net/
COMMENT=	JDBC-based cross-platform SQL query tool
# Apache, except not granted to certain entities
LICENSE=	generic-nonlicense

RESTRICTED=		Some entities are not permitted to use/download.
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

EXTRACT_DIR=	${WRKSRC}

USE_JAVA=		run
USE_JAVA2=		11
USE_TOOLS+=		pax

INSTALLATION_DIRS=	bin share/${PKGBASE}
CHECK_INTERPRETER_SKIP=	share/sql-workbench/sqlwbconsole.sh \
			share/sql-workbench/sqlworkbench.sh \
			share/sql-workbench/download_jre.sh

pre-extract:
	mkdir -p ${WRKSRC}

do-build:
	printf "#!/bin/sh\n${PKG_JAVA_HOME}/bin/java -Dvisualvm.display.name=SQLWorkbench -Xmx512m -jar ${PREFIX}/share/${PKGBASE}/sqlworkbench.jar \$${1:+\"\$$@\"}\n" > ${WRKDIR}/sqlworkbench.sh

do-install:
	cd ${WRKSRC} && ${PAX} -rwpm -s /\.orig$$// . ${DESTDIR}${PREFIX}/share/${PKGBASE}
	${INSTALL_SCRIPT} ${WRKDIR}/sqlworkbench.sh ${DESTDIR}${PREFIX}/bin/sqlworkbench

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
