# $NetBSD: Makefile,v 1.1 2015/08/26 10:57:30 tnn Exp $

DISTNAME=	jd-gui-1.4.0
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=java-decompiler/}
EXTRACT_SUFX=	.jar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://java-decompiler.github.io/
COMMENT=	Standalone Java byte code decompiler
LICENSE=	gnu-gpl-v3

NO_CONFIGURE=	yes
USE_JAVA=	yes
USE_JAVA2=	8

INSTALLATION_DIRS=	bin lib/java/jd-gui

do-build:
	printf "#! /bin/sh\\nexec %s -jar %s \"%s\"\\n"			\
		${JAVA_BINPREFIX}-java					\
		${PREFIX}/lib/java/jd-gui/${DISTNAME}${EXTRACT_SUFX}	\
		'$$@'						>	\
		${WRKDIR}/jd-gui

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/jd-gui ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}${EXTRACT_SUFX} ${DESTDIR}${PREFIX}/lib/java/jd-gui

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
