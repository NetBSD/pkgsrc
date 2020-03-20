# $NetBSD: Makefile,v 1.3 2020/03/20 11:58:15 nia Exp $

DISTNAME=	PortableSigner-Generic-2.0.38c0573
PKGNAME=	${DISTNAME:S/-Generic//}
CATEGORIES=	security
MASTER_SITES=	http://sourceforge.net/projects/portablesigner/files/portablesigner/2.0-Release/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://portablesigner.sourceforge.net/
COMMENT=	Tool for digital signing (with X.509 certificates) of PDF files
LICENSE=	eupl-v1.1

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
USE_JAVA=	run
USE_JAVA2=	yes

INSTALLATION_DIRS=	bin lib/PortableSigner/lib share/applications share/doc/PortableSigner

do-build:
	${ECHO} '#!/bin/sh' > ${WRKDIR}/PortableSigner.sh
	${ECHO} "exec ${JAVA_BINPREFIX}-java -cp \"${PREFIX}/lib/PortableSigner/lib/*\" -jar ${PREFIX}/lib/PortableSigner/PortableSigner.jar "'"$$@"' >> ${WRKDIR}/PortableSigner.sh

do-install:
	cd ${WRKSRC} && cp PortableSigner.jar ${DESTDIR}${PREFIX}/lib/PortableSigner
	# must be lib, hardcoded in PortableSigner.jar
	cd ${WRKSRC} && cp lib/* ${DESTDIR}${PREFIX}/lib/PortableSigner/lib
	${INSTALL_SCRIPT} ${WRKDIR}/PortableSigner.sh ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/linux/PortableSignerLogo.png ${DESTDIR}${PREFIX}/share/doc/PortableSigner
	${INSTALL_DATA} ${WRKDIR}/linux/Readme.txt ${DESTDIR}${PREFIX}/share/doc/PortableSigner
	${INSTALL_DATA} ${WRKDIR}/linux/portablesigner.desktop ${DESTDIR}${PREFIX}/share/applications

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
