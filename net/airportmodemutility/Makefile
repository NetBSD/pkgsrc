# $NetBSD: Makefile,v 1.13 2010/02/11 20:22:28 joerg Exp $

DISTNAME=	${BINNAME}_20
PKGNAME=	${BINNAME}-2.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://edge.mcs.drexel.edu/GICL/people/sevy/airport/
COMMENT=	Modem (dis)connection utility for Apple's Airport Base Station

PKG_DESTDIR_SUPPORT=	user-destdir

PLIST_SUBST+=	BINNAME=${BINNAME:Q} JARNAME=${JARNAME:Q}

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-powerpc Darwin-*-*

BINNAME=	airportmodemutility
DOCDIR=		${PREFIX}/share/doc/${BINNAME}
JARNAME=	AirportModemUtility.jar
LIBDIR=		${PREFIX}/lib/${BINNAME}

.include "../../mk/bsd.prefs.mk"

USE_JAVA=		run
PKG_JVMS_ACCEPTED=	sun-jdk13 sun-jdk14 blackdown-jdk13 jdk14

INSTALLATION_DIRS=	bin ${DOCDIR} ${LIBDIR}

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
	cd ${WRKSRC} && \
	${INSTALL_SCRIPT} ${BINNAME} ${DESTDIR}${PREFIX}/bin && \
	${INSTALL_DATA} ${JARNAME} ${DESTDIR}${LIBDIR} && \
	${INSTALL_DATA} AUTHORS ${DESTDIR}${DOCDIR} && \
	${INSTALL_DATA} COPYING ${DESTDIR}${DOCDIR} && \
	${INSTALL_DATA} README ${DESTDIR}${DOCDIR}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"

.if ${PKG_JVM} == "blackdown-jdk13"
JVM_OPTS+=	-green -jar
.else
JVM_OPTS+=	-jar
.endif
