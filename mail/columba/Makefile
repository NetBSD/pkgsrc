# $NetBSD: Makefile,v 1.5 2004/04/09 17:09:58 jmmv Exp $
#

DISTNAME=	columba-unix-1.0_M2-bin
PKGNAME=	columba-1.0M2
CATEGORIES=	mail
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=columba/}
EXTRACT_SUFX=	.zip

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://columba.sourceforge.net/
COMMENT=	Graphical Email Client written in JAVA (TM)

NO_BUILD=		yes
USE_BUILDLINK2=		yes
USE_JAVA2=		yes
PKG_JVMS_ACCEPTED=	sun-jdk13 sun-jdk14 jdk13

SUBST_CLASSES=		columba
SUBST_STAGE.columba=	pre-configure
SUBST_MESSAGE.columba=	"Fixing path to columba\'s executable."
SUBST_FILES.columba=	run.sh
SUBST_SED.columba=	-e 's,columba.jar,${PREFIX}/share/${PKGBASE}/columba.jar,'

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/${PKGBASE}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/lib/* ${PREFIX}/share/${PKGBASE}/lib
	${INSTALL_DATA} ${WRKSRC}/columba.jar ${PREFIX}/share/${PKGBASE}
.for f in AUTHORS LICENSE CHANGES README
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/${PKGBASE}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/run.sh ${PREFIX}/bin/columba

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
