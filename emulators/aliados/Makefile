# $NetBSD: Makefile,v 1.1.1.1 2004/11/09 05:47:28 minskim Exp $
#

DISTNAME=		aliados-0.1.1
CATEGORIES=		emulators
MASTER_SITES=		http://www.arrakis.es/~ninsesabe/aliados/
EXTRACT_SUFX=		.tgz

MAINTAINER=		ivaniclixx@gmail.com
HOMEPAGE=		http://www.arrakis.es/~ninsesabe/aliados/
COMMENT=		CP/M 80 emulator

PKG_INSTALLATION_TYPES= overwrite pkgviews

USE_BUILDLINK3=		YES
NO_CONFIGURE=		YES
USE_LANGUAGES=		c++
USE_NCURSES=		# tigetstr tparm setupterm

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aliados ${PREFIX}/bin/

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
