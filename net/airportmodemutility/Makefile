# $NetBSD: Makefile,v 1.1.1.1 2003/03/22 14:45:47 tron Exp $

DISTNAME=	${BINNAME}_20
PKGNAME=	${BINNAME}-2.0
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	.zip

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://edge.mcs.drexel.edu/GICL/people/sevy/airport/
COMMENT=	Modem (dis)connection utility for Apple's Airport Base Station

PLIST_SUBST+=	BINNAME=${BINNAME} JARNAME=${JARNAME}

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-powerpc Darwin-*-*

BINNAME=	airportmodemutility
DOCDIR=		${PREFIX}/share/doc/${BINNAME}
JARNAME=	AirportModemUtility.jar
LIBDIR=		${PREFIX}/lib/${BINNAME}

.include "../../mk/bsd.prefs.mk"

USE_BUILDLINK2=		# defined
USE_JAVA=		run
PKG_JVMS_ACCEPTED=	sun-jdk13 sun-jdk14 blackdown-jdk13

post-extract:
	${CHMOD} -R g-w,o-w ${WRKSRC}/*

do-build:
	${ECHO} "#!/bin/sh" >${WRKSRC}/${BINNAME}
	${ECHO} "PATH=${PKG_JAVA_HOME}/bin:\$${PATH}; export PATH" >>${WRKSRC}/${BINNAME}
.if defined(CLASSPATH)
	${ECHO} "CLASSPATH=${CLASSPATH}:\$${CLASSPATH}; export CLASSPATH" >>${WRKSRC}/${BINNAME}
.endif
	${ECHO} "exec java ${JVM_OPTS} ${LIBDIR}/${JARNAME}" >>${WRKSRC}/${BINNAME}

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR} ${LIBDIR}
	cd ${WRKSRC} && \
	${INSTALL_SCRIPT} ${BINNAME} ${PREFIX}/bin && \
	${INSTALL_DATA} ${JARNAME} ${LIBDIR} && \
	${INSTALL_DATA} AUTHORS ${DOCDIR} && \
	${INSTALL_DATA} COPYING ${DOCDIR} && \
	${INSTALL_DATA} README ${DOCDIR}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"

.if ${PKG_JVM} == "blackdown-jdk13"
JVM_OPTS+=	-green -jar
.else
JVM_OPTS+=	-jar
.endif
