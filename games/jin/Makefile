# $NetBSD: Makefile,v 1.5 2020/03/20 11:57:42 nia Exp $

DISTNAME=	jin-2.14.1-unix
PKGNAME=	${DISTNAME:S/-unix//}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=jin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jin.sourceforge.net/
COMMENT=	Graphical client for chess servers
LICENSE=	gnu-gpl-v2

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=		# none
USE_TOOLS+=		pax
USE_JAVA=		run
USE_JAVA2=		yes
INSTALLATION_DIRS=	bin share/${PKGBASE}

do-build:
	${ECHO} '#!/bin/sh' > ${WRKDIR}/jin.sh
	${ECHO} "cd ${PREFIX}/share/${PKGBASE} && exec ${JAVA_BINPREFIX}-java -jar "'"'"jin.jar"'" "$$@"' >> ${WRKDIR}/jin.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/jin.sh ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && pax -pp -rw * ${DESTDIR}${PREFIX}/share/${PKGBASE}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
