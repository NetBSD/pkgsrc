# $NetBSD: Makefile,v 1.9 2002/02/08 19:24:21 tron Exp $

DISTNAME=	configurator
PKGNAME=	${BINNAME}-1.2.2
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	.zip

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://edge.mcs.drexel.edu/GICL/people/sevy/airport/
COMMENT=	Configuration program for Apple's Airport Base Station

USE_JAVA=	YES

DIST_SUBDIR=	${PKGNAME}
PLIST_SUBST+=	BINNAME=${BINNAME}
WRKSRC=		${WRKDIR}

BINNAME=	airportbasestationconfig
DOCDIR=		${PREFIX}/share/doc/${BINNAME}
LIBDIR=		${PREFIX}/lib/${BINNAME}

.include "../../mk/bsd.prefs.mk"

# "jdk" and "kaffe" packages don't work.
.if ${MACHINE_ARCH} == i386
PKG_JVM=	sun-jdk
.elif ${MACHINE_ARCH} == powerpc
PKG_JVM=	blackdown-jdk13
.endif

.if ${PKG_JVM} == blackdown-jdk13
JVM_OPTS+=	-green -jar
.else
JVM_OPTS=	-jar
.endif

post-extract:
	${CHMOD} -R g-w,o-w ${WRKSRC}/*

do-build:
	${ECHO} "#!/bin/sh" >${WRKSRC}/${BINNAME}
	${ECHO} "PATH=${JAVA_HOME}/bin:\$${PATH}; export PATH" >>${WRKSRC}/${BINNAME}
.if defined(CLASSPATH)
	${ECHO} "CLASSPATH=${CLASSPATH}:\$${CLASSPATH}; export CLASSPATH" >>${WRKSRC}/${BINNAME}
.endif
	${ECHO} "exec java ${JVM_OPTS} ${LIBDIR}/${BINNAME}.jar" >>${WRKSRC}/${BINNAME}

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR} ${LIBDIR}
	cd ${WRKSRC} && \
	${INSTALL_SCRIPT} ${BINNAME} ${PREFIX}/bin && \
	${INSTALL_DATA} ${BINNAME}.jar ${LIBDIR} && \
	${INSTALL_DATA} authors ${DOCDIR}/AUTHORS && \
	${INSTALL_DATA} copying ${DOCDIR}/COPYING
	cd ${WRKSRC}/helpdocs && \
	${INSTALL_DATA} readme.txt ${DOCDIR}/README && \
	${INSTALL_DATA} mainscreen.jpg manual.html ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
