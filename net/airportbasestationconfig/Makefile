# $NetBSD: Makefile,v 1.27 2005/06/17 03:50:23 jlam Exp $

DISTNAME=	configurator_152-128
PKGNAME=	${BINNAME}-1.5.2
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	.zip

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://edge.mcs.drexel.edu/GICL/people/sevy/airport/
COMMENT=	Configuration program for Apple's Airport Base Station

PLIST_SUBST+=	BINNAME=${BINNAME} JARNAME=${JARNAME}

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-powerpc Darwin-*-*

BINNAME=	airportbasestationconfig
DOCDIR=		${PREFIX}/share/doc/${BINNAME}
JARNAME=	AirportConfig128Bit.jar
LIBDIR=		${PREFIX}/lib/${BINNAME}

USE_JAVA=		run
PKG_JVMS_ACCEPTED=	sun-jdk13 sun-jdk14 blackdown-jdk13 jdk13 jdk14

INSTALLATION_DIRS=	bin

post-extract:
	${CHMOD} -R g-w,o-w ${WRKSRC}/*

do-build:
	${ECHO} "#!/bin/sh" >${WRKSRC}/${BINNAME}
	${ECHO} "PATH=${PKG_JAVA_HOME}/bin:\$${PATH}; export PATH" >>${WRKSRC}/${BINNAME}
.if defined(CLASSPATH)
	${ECHO} "CLASSPATH=${CLASSPATH}:\$${CLASSPATH}; export CLASSPATH" >>${WRKSRC}/${BINNAME}
.endif
	${ECHO} '${ULIMIT_CMD_datasize}' >>${WRKSRC}/${BINNAME}
	${ECHO} "exec java -jar ${LIBDIR}/${JARNAME}" >>${WRKSRC}/${BINNAME}

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR} ${LIBDIR}
	cd ${WRKSRC} && \
	${INSTALL_SCRIPT} ${BINNAME} ${PREFIX}/bin && \
	${INSTALL_DATA} ${JARNAME} ${LIBDIR} && \
	${INSTALL_DATA} AUTHORS ${DOCDIR} && \
	${INSTALL_DATA} COPYING ${DOCDIR} && \
	cd helpdocs && \
	${INSTALL_DATA} ReadMe.txt ${DOCDIR}/README && \
	${INSTALL_DATA} mainscreen.jpg manual.html ${DOCDIR}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
