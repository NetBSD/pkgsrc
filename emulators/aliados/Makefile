# $NetBSD: Makefile,v 1.2 2005/04/11 21:45:42 tv Exp $
#

DISTNAME=		aliados-0.1.1
CATEGORIES=		emulators
MASTER_SITES=		http://www.arrakis.es/~ninsesabe/aliados/
EXTRACT_SUFX=		.tgz

MAINTAINER=		ivaniclixx@gmail.com
HOMEPAGE=		http://www.arrakis.es/~ninsesabe/aliados/
COMMENT=		CP/M 80 emulator

PKG_INSTALLATION_TYPES= overwrite pkgviews

NO_CONFIGURE=		YES
USE_LANGUAGES=		c++
USE_NCURSES=		# tigetstr tparm setupterm

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aliados ${PREFIX}/bin/

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
