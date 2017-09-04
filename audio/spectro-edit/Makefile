# $NetBSD: Makefile,v 1.2 2017/09/04 18:55:07 wiz Exp $

DISTNAME=	spectro-edit_0.4
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	audio
MASTER_SITES=	https://spectro-edit.googlecode.com/files/
EXTRACT_SUFX=	.jar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/archive/p/spectro-edit/
COMMENT=	Graphically view and edit WAV files
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
INSTALLATION_DIRS=	bin share/spectro-edit

USE_JAVA=	run
USE_JAVA2=	yes

do-build:
	${ECHO} '#!/bin/sh' > ${WRKDIR}/spectro-edit.sh
	${ECHO} "exec ${JAVA_BINPREFIX}-java -jar "'"'"${PREFIX}"'/share/spectro-edit/${DISTNAME}.jar" "$$@"' >> ${WRKDIR}/spectro-edit.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/spectro-edit.sh ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar ${DESTDIR}${PREFIX}/share/spectro-edit

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
