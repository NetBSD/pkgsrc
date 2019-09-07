# $NetBSD: Makefile,v 1.4 2019/09/07 07:11:46 rillig Exp $

PKGNAME=	ini_file_manager-${IFM_VERSION}
CATEGORIES=	misc
MASTER_SITES=	http://sourceforge.net/projects/${SFPATH}/
DISTFILES=	ini-files-${IFM_VERSION}.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/ini-files
COMMENT=	Ini configuration file reader and manipulator package for Ada
LICENSE=	mit

IFM_VERSION=	03
SFPATH=		ini-files/files/ini-files/ini-files-${IFM_VERSION}

USE_LANGUAGES=	ada

post-extract:
	@${MKDIR} ${WRKSRC}/src
	${CP} ${FILESDIR}/construct.gpr ${WRKSRC}
	${MV} ${WRKDIR}/config.ad[bs] ${WRKSRC}/src/

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gnatmake -p -Pconstruct)

do-install:
	${MKDIR} ${DESTDIR}${PREFIX}/lib/gnat \
		${DESTDIR}${PREFIX}/lib/ini_file_manager \
		${DESTDIR}${PREFIX}/include/ini_file_manager
	${INSTALL_DATA} ${FILESDIR}/ini_file_manager.gpr \
		${DESTDIR}${PREFIX}/lib/gnat
	${INSTALL_DATA} ${WRKSRC}/src/* \
		${DESTDIR}${PREFIX}/include/ini_file_manager
	${INSTALL_DATA} ${WRKSRC}/lib/*  \
		${DESTDIR}${PREFIX}/lib/ini_file_manager

.include "../../mk/bsd.pkg.mk"
