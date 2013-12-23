# $NetBSD: Makefile,v 1.13 2013/12/23 11:57:03 wiz Exp $

DISTNAME=	dmake-v4.1-src-export.all-unknown-all
PKGNAME=	dmake-4.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://dmake.wticorp.com/SourceDistribution/ \
		ftp://plg.uwaterloo.ca/pub/dmake/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dmake.wticorp.com/
COMMENT=	Portable make supported by many platforms

MAKE_FILE=	makefile
BUILD_TARGET=	linux
WRKSRC=		${WRKDIR}/dmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-configure:
	cd ${WRKSRC} && ${RM} unix/bsd43/dirent.h &&		\
	${CP} unix/startup.h unix/startup.h.orig &&		\
	${SED} -e "s:/usr/local/lib:${PREFIX}/share:g"	\
		<unix/startup.h.orig >unix/startup.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dmake ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/dmake.tf \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/dmake.1
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/dmake
	${CP} -pR ${WRKSRC}/startup ${DESTDIR}${PREFIX}/share/dmake

.include "../../mk/bsd.pkg.mk"
