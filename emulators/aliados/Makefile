# $NetBSD: Makefile,v 1.12 2023/08/02 19:20:20 nia Exp $
#

DISTNAME=		aliados-0.2.0
PKGREVISION=		2
CATEGORIES=		emulators
MASTER_SITES=		http://www.arrakis.es/~ninsesabe/aliados/
EXTRACT_SUFX=		.tgz

MAINTAINER=		ivaniclixx@gmail.com
HOMEPAGE=		http://www.arrakis.es/~ninsesabe/aliados/
COMMENT=		CP/M 80 emulator

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_NCURSES=		yes # tigetstr tparm setupterm

INSTALLATION_DIRS=	bin share/doc/aliados

# Fails with C++14 default language.
FORCE_CXX_STD=		c++03

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aliados ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/aliados
	${INSTALL_DATA} ${WRKSRC}/aliadosdoc.html ${DESTDIR}${PREFIX}/share/doc/aliados

.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
