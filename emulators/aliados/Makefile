# $NetBSD: Makefile,v 1.4 2010/03/17 14:17:38 joerg Exp $
#

DISTNAME=		aliados-0.1.1
CATEGORIES=		emulators
MASTER_SITES=		http://www.arrakis.es/~ninsesabe/aliados/
EXTRACT_SUFX=		.tgz

MAINTAINER=		ivaniclixx@gmail.com
HOMEPAGE=		http://www.arrakis.es/~ninsesabe/aliados/
COMMENT=		CP/M 80 emulator

PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		YES
USE_LANGUAGES=		c++
USE_NCURSES=		yes # tigetstr tparm setupterm

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aliados ${DESTDIR}${PREFIX}/bin

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
