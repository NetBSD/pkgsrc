# $NetBSD: Makefile,v 1.4 2009/05/21 00:41:34 zafer Exp $
#

DISTNAME=	CRWInfo-0.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GENTOO:=distfiles/}

MAINTAINER=	kirtai@users.sourceforge.net
HOMEPAGE=	http://neuemuenze.heim1.tu-clausthal.de/~sven/crwinfo/
COMMENT=	Extracts exposure information and thumbnails from Canon RAW files

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/crwinfo ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/crwinfo/
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/crwinfo/

.include "../../mk/bsd.pkg.mk"
