# $NetBSD: Makefile,v 1.1.1.1 2000/10/15 12:46:21 rh Exp $
#

DISTNAME=	dmake-v4.1-src-export.all-unknown-all
PKGNAME=	dmake-4.1
WRKSRC=		${WRKDIR}/dmake
CATEGORIES=	devel
MASTER_SITES=	http://dmake.wticorp.com/SourceDistribution/ \
		ftp://plg.uwaterloo.ca/pub/dmake/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://dmake.wticorp.com/

MAKEFILE=	makefile
ALL_TARGET=	linux

do-configure:
	cd ${WRKSRC} && ${RM} unix/bsd43/dirent.h &&		\
	${CP} unix/startup.h unix/startup.h.orig &&		\
	${SED} -e "s:/usr/local/lib:${PREFIX}/share:g"	\
		<unix/startup.h.orig >unix/startup.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dmake ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/dmake
	${CP} -pR ${WRKSRC}/startup ${PREFIX}/share/dmake

.include "../../mk/bsd.pkg.mk"
