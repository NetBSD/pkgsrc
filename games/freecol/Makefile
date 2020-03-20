# $NetBSD: Makefile,v 1.3 2020/03/20 11:57:41 nia Exp $

DISTNAME=	freecol-0.11.6
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freecol/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://freecol.sourceforge.net/
COMMENT=	Turn-based strategy game based on the old game Colonization
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/freecol
USE_LANGUAGES=	# none

USE_JAVA=	run
USE_JAVA2=	yes

INSTALLATION_DIRS=	bin share/freecol share/docs/freecol

do-build:
	${SED} "s,@PREFIX@,${PREFIX},g" ${FILESDIR}/freecol.sh > ${WRKDIR}/freecol.sh
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} 644 {} \;
	${FIND} ${WRKSRC} -type d -exec ${CHMOD} 755 {} \;

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/freecol.sh ${DESTDIR}${PREFIX}/bin/freecol
	#${INSTALL_DATA} ${WRKSRC}/freecol.desktop ${DESTDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/FreeCol.jar ${DESTDIR}${PREFIX}/share/freecol
	cd ${WRKSRC} && ${CP} -R data ${DESTDIR}${PREFIX}/share/freecol
	cd ${WRKSRC} && ${CP} -R jars ${DESTDIR}${PREFIX}/share/freecol
	${INSTALL_DATA} ${WRKSRC}/FreeCol.pdf ${DESTDIR}${PREFIX}/share/docs/freecol

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
