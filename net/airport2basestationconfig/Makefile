# $NetBSD: Makefile,v 1.1.1.1 2003/06/05 12:31:35 markd Exp $

DISTNAME=	configurator_201
PKGNAME=	${BINNAME}-2.0.1
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	.zip

MAINTAINER=	markd@netbsd.org
HOMEPAGE=	http://edge.mcs.drexel.edu/GICL/people/sevy/airport/
COMMENT=	Configuration program for Apple's Airport Base Station

PLIST_SUBST+=	BINNAME=${BINNAME} JARNAME=${JARNAME}

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-powerpc Darwin-*-*

WRKSRC=		${WRKDIR}/configurator_20
BINNAME=	airport2basestationconfig
DOCDIR=		${PREFIX}/share/doc/${BINNAME}
JARNAME=	Airport2BaseStationConfig.jar
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
