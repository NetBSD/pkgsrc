# $NetBSD: Makefile,v 1.14 2017/08/01 16:47:41 wiz Exp $

DISTNAME=	configurator_201
PKGNAME=	${BINNAME}-2.0.1
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://edge.mcs.drexel.edu/GICL/people/sevy/airport/
COMMENT=	Configuration program for Apple's Airport Base Station

PLIST_SUBST+=	BINNAME=${BINNAME:Q} JARNAME=${JARNAME:Q}

WRKSRC=		${WRKDIR}/configurator_20
BINNAME=	airport2basestationconfig
DOCDIR=		${PREFIX}/share/doc/${BINNAME}
JARNAME=	Airport2BaseStationConfig.jar
LIBDIR=		${PREFIX}/lib/${BINNAME}

.include "../../mk/bsd.prefs.mk"

USE_JAVA=		run
PKG_JVMS_ACCEPTED=	sun-jdk13 sun-jdk14 sun-jdk15 blackdown-jdk13 jdk14

INSTALLATION_DIRS=	bin share/doc/${BINNAME} lib/${BINNAME}

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
	cd ${WRKSRC} && \
	${INSTALL_SCRIPT} ${BINNAME} ${DESTDIR}${PREFIX}/bin && \
	${INSTALL_DATA} ${JARNAME} ${DESTDIR}${LIBDIR} && \
	${INSTALL_DATA} AUTHORS ${DESTDIR}${DOCDIR} && \
	${INSTALL_DATA} COPYING ${DESTDIR}${DOCDIR} && \
	cd helpdocs && \
	${INSTALL_DATA} ReadMe.txt ${DESTDIR}${DOCDIR}/README && \
	${INSTALL_DATA} mainscreen.jpg manual.html ${DESTDIR}${DOCDIR}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
