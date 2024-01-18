# $NetBSD: Makefile,v 1.4 2024/01/18 13:53:05 abs Exp $

DISTNAME=	restclient-ui-fat-3.7.2
PKGNAME=	restclient-ui-3.7.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=abs0/}rest-client/releases/download/3.7.2/
EXTRACT_SUFX=	.jar

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	https://github.com/abs0/rest-client
COMMENT=	Java application to test RESTful webservices
LICENSE=	apache-2.0

NO_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_JAVA=	yes
USE_JAVA2=	yes
WRKSRC=		${WRKDIR}

LIBDIR=			lib/java/restclient-ui
INSTALLATION_DIRS=	bin ${LIBDIR}

do-build:
	printf "#! /bin/sh\\nexec %s -jar %s \"%s\"\\n"			\
		${PREFIX}/bin/java					\
		${PREFIX}/${LIBDIR}/${DISTNAME}${EXTRACT_SUFX}	\
		'$$@'						>	\
		${WRKDIR}/restclient-ui

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/restclient-ui ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}${EXTRACT_SUFX} ${DESTDIR}${PREFIX}/${LIBDIR}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
