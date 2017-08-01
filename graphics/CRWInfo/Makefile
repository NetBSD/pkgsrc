# $NetBSD: Makefile,v 1.6 2017/08/01 17:40:12 wiz Exp $
#

DISTNAME=	CRWInfo-0.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GENTOO:=distfiles/}

MAINTAINER=	kirtai@users.sourceforge.net
#HOMEPAGE=	http://neuemuenze.heim1.tu-clausthal.de/~sven/crwinfo/
COMMENT=	Extracts exposure information and thumbnails from Canon RAW files

NO_CONFIGURE=		yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/crwinfo ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/crwinfo/
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/crwinfo/

.include "../../mk/bsd.pkg.mk"
