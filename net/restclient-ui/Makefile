# $NetBSD: Makefile,v 1.1.1.1 2016/01/11 13:47:01 abs Exp $

DISTNAME=	${PKGNAME}-jar-with-dependencies
PKGNAME=	restclient-ui-3.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=wiztools/}rest-client/releases/download/restclient-3.5/
EXTRACT_SUFX=	.jar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wiztools/rest-client
COMMENT=	Java application to test RESTful webservices
LICENSE=	apache-2.0

NO_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_JAVA=	yes
USE_JAVA2=	yes
WRKSRC=		${WRKDIR}

LIBDIR=		lib/java/restclient-ui
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
