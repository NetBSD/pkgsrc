# $NetBSD: Makefile,v 1.26 2011/12/19 13:44:07 wiz Exp $

DISTNAME=	plp_1_8
PKGNAME=	plp-1.8
PKGREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://web.archive.org/web/20031214215022/http://www.proudman51.freeserve.co.uk/psion/
COMMENT=	Tools to talk to the PSION organiser

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
MAKE_JOBS_SAFE=	no

INSTALLATION_DIRS=	bin lib

do-install:
	${LIBTOOL} --mode=install ${INSTALL_DATA} ${WRKSRC}/utils/libplputils.la ${DESTDIR}${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/ncp/ncp ${DESTDIR}${PREFIX}/bin
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/rfsv/rfsv ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/plp
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/plp

.include "../../mk/bsd.pkg.mk"
