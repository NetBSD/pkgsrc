# $NetBSD: Makefile,v 1.5 2012/05/15 11:34:52 shattered Exp $
#

DISTNAME=		aliados-0.1.1
PKGREVISION=		1
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

INSTALLATION_DIRS=	bin share/doc/aliados

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aliados ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/aliados
	${INSTALL_DATA} ${WRKSRC}/aliados.doc ${DESTDIR}${PREFIX}/share/doc/aliados

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
