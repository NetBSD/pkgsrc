# $NetBSD: Makefile,v 1.14 2012/10/31 11:17:31 asau Exp $
#

DISTNAME=	NetBeansIDE-release351
PKGNAME=	netbeans-ide-3.5.1
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	http://www.netbeans.org/download/release351/night/build200307252351/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	drue@users.sourceforge.net
HOMEPAGE=	http://www.netbeans.org/
COMMENT=	NetBeans Java IDE

USE_TOOLS+=	pax
USE_JAVA=	run
PKG_JVMS_ACCEPTED=  sun-jdk13 sun-jdk14 jdk14 sun-jdk15 jdk15 sun-jdk6 jdk6
PKG_JVMS_ACCEPTED+= openjdk7
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
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${SHAREDIR}
	cd ${WRKSRC}/docs && pax -rwpm . ${DESTDIR}${DOCDIR}
	for f in CHANGES.html CREDITS.html README.html netbeans.css; \
	do \
		${INSTALL_DATA} ${WRKSRC}/$${f} ${DESTDIR}${DOCDIR}; \
	done
	cd ${WRKSRC} && pax -rwpm beans bin lib modules system \
	    tomcat406 update_tracking ${DESTDIR}${SHAREDIR}
	${LN} -sf ${SHAREDIR}/bin/runide.sh ${DESTDIR}${PREFIX}/bin/netbeans

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
