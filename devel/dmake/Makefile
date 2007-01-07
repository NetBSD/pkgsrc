# $NetBSD: Makefile,v 1.10 2007/01/07 09:13:50 rillig Exp $
#

DISTNAME=	dmake-v4.1-src-export.all-unknown-all
PKGNAME=	dmake-4.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://dmake.wticorp.com/SourceDistribution/ \
		ftp://plg.uwaterloo.ca/pub/dmake/

MAINTAINER=	rh@NetBSD.org
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
	${INSTALL_PROGRAM} ${WRKSRC}/dmake ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/dmake.tf ${PREFIX}/${PKGMANDIR}/man1/dmake.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/dmake
	${CP} -pR ${WRKSRC}/startup ${PREFIX}/share/dmake

.include "../../mk/bsd.pkg.mk"
