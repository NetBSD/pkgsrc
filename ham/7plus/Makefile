# $NetBSD: Makefile,v 1.13 2008/06/12 02:14:32 joerg Exp $
#

DISTNAME=	7pl225sr
PKGNAME=	7plus-225
PKGREVISION=	1
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_BACKUP}
DISTFILES=	7pl225sr.tgz \
		7pl210mg.tgz

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	#http://home.t-online.de/home/dg1bbq/
COMMENT=	Uuencode-like file coder for AMPR BBS S&F of binary files

PKG_DESTDIR_SUPPORT=	user-destdir

LICENSE=	no-commercial-use

WRKSRC=		${WRKDIR}/7plsrc.225
MAKE_FILE=	netbsd.mak
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin share/doc/7plus

post-install:
	${INSTALL_DATA} ${WRKDIR}/*.txt ${DESTDIR}${PREFIX}/share/doc/7plus && \
	${INSTALL_DATA} ${WRKDIR}/readme.now ${DESTDIR}${PREFIX}/share/doc/7plus

.include "../../mk/bsd.pkg.mk"
