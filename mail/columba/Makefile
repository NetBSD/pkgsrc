# $NetBSD: Makefile,v 1.2 2004/04/08 14:55:53 xtraeme Exp $
#

DISTNAME=	columba-unix-1.0_M2-bin
PKGNAME=	columba-1.0M2
CATEGORIES=	mail
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=columba/}
EXTRACT_SUFX=	.zip

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://columba.sourceforge.net/
COMMENT=	Graphical Email Client written in JAVA (TM)

USE_BUILDLINK2=	yes
NO_BUILD=	yes
USE_JAVA2=	yes
PKG_JVMS_ACCEPTED=  sun-jdk13 sun-jdk14 jdk13

COLUMBA_BIN=	    ${PREFIX}/share/${PKGBASE}/columba.jar

SUBST_CLASSES=	    foo
SUBST_STAGE.foo=    post-patch
SUBST_FILES.foo=    run.sh
SUBST_SED.foo=	    -e "s,columba.jar,${COLUMBA_BIN},"
SUBST_MESSAGE.foo=  "Fixing columba\'s executable path."

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/${PKGBASE}
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
