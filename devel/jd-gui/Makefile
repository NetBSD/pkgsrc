# $NetBSD: Makefile,v 1.2 2016/01/11 13:52:00 abs Exp $

DISTNAME=	jd-gui-1.4.0
PKGREVISION=	1
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
WRKSRC=		${WRKDIR}

LIBDIR=		lib/java/jd-gui
INSTALLATION_DIRS=	bin ${LIBDIR}

do-build:
	printf "#! /bin/sh\\nexec %s -jar %s \"%s\"\\n"			\
		${PREFIX}/bin/java					\
		${PREFIX}/${LIBDIR}/${DISTNAME}${EXTRACT_SUFX}	\
		'$$@'						>	\
		${WRKDIR}/jd-gui

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/jd-gui ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}${EXTRACT_SUFX} ${DESTDIR}${PREFIX}/${LIBDIR}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
