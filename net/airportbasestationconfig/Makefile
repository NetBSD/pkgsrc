# $NetBSD: Makefile,v 1.2 2001/01/06 08:58:08 tron Exp $

DISTNAME=	configurator
PKGNAME=	${BINNAME}-1.2.2
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	.zip

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://edge.mcs.drexel.edu/GICL/people/sevy/airport/

# "jdk" and "kaffe" packages don't work.
DEPENDS+=	sun-jdk>=1.3.0:../../lang/sun-jdk13

BINNAME=	airportbasestationconfig
DOCDIR=		${PREFIX}/share/doc/${BINNAME}
DIST_SUBDIR=	${PKGNAME}
LIBDIR=		${PREFIX}/lib/${BINNAME}
PKG_JVM=	jdk
PLIST_SUBST+=	BINNAME=${BINNAME}
USE_JAVA=	YES
WRKSRC=		${WRKDIR}

post-extract:
	${CHMOD} -R g-w,o-w ${WRKSRC}/*

do-build:
	cd ${WRKSRC} && \
	${ECHO} "#!/bin/sh" >${BINNAME} && \
	${ECHO} "PATH=${JAVA_HOME}/bin:\$${PATH}; export PATH" >>${BINNAME} && \
	${ECHO} "exec java -jar ${LIBDIR}/${BINNAME}.jar" >>${BINNAME}

do-install:
	${MKDIR} ${DOCDIR} ${LIBDIR}
	cd ${WRKSRC} && \
	${INSTALL_SCRIPT} ${BINNAME} ${PREFIX}/bin && \
	${INSTALL_DATA} ${BINNAME}.jar ${LIBDIR} && \
	${INSTALL_DATA} authors ${DOCDIR}/AUTHORS && \
	${INSTALL_DATA} copying ${DOCDIR}/COPYING
	cd ${WRKSRC}/helpdocs && \
	${INSTALL_DATA} readme.txt ${DOCDIR}/README && \
	${INSTALL_DATA} mainscreen.jpg manual.html ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
