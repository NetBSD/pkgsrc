# $NetBSD: Makefile,v 1.6 2005/06/16 06:57:47 jlam Exp $
#

DISTNAME=	NetBeansIDE-release351
PKGNAME=	netbeans-ide-3.5.1
CATEGORIES=	editors
MASTER_SITES=	http://www.netbeans.org/download/release351/night/build200307252351/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	drue@users.sourceforge.net
HOMEPAGE=	http://www.netbeans.org/
COMMENT=	NetBeans Java IDE

USE_JAVA=	run
PKG_JVMS_ACCEPTED=  sun-jdk13 sun-jdk14 jdk13 jdk14
NO_CONFIGURE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/netbeans

SHAREDIR=	${PREFIX}/share/${PKGBASE}
DOCDIR=		${PREFIX}/share/doc/html/${PKGBASE}

INSTALLATION_DIRS=	bin

pre-install:
	cd ${WRKSRC}/bin && ${RM} -rf *.exe *.cmd *.com \
	    runide_exe_defaults unsupported

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${SHAREDIR}
	cd ${WRKSRC}/docs && ${PAX} -rwpm . ${DOCDIR}
	for f in CHANGES.html CREDITS.html README.html netbeans.css; \
	do \
		${INSTALL_DATA} ${WRKSRC}/$${f} ${DOCDIR}; \
	done
	cd ${WRKSRC} && ${PAX} -rwpm beans bin lib modules system \
	    tomcat406 update_tracking ${SHAREDIR}
	${LN} -sf ${SHAREDIR}/bin/runide.sh  ${PREFIX}/bin/netbeans

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
