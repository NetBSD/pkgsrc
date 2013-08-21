# $NetBSD: Makefile,v 1.7 2013/08/21 10:23:41 shattered Exp $
#

DISTNAME=		aliados-0.2.0
CATEGORIES=		emulators
MASTER_SITES=		http://www.arrakis.es/~ninsesabe/aliados/
EXTRACT_SUFX=		.tgz

MAINTAINER=		ivaniclixx@gmail.com
HOMEPAGE=		http://www.arrakis.es/~ninsesabe/aliados/
COMMENT=		CP/M 80 emulator

PKG_INSTALLATION_TYPES= overwrite pkgviews

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_NCURSES=		yes # tigetstr tparm setupterm

INSTALLATION_DIRS=	bin share/doc/aliados

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aliados ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/aliados
	${INSTALL_DATA} ${WRKSRC}/aliadosdoc.html ${DESTDIR}${PREFIX}/share/doc/aliados

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
