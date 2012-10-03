# $NetBSD: Makefile,v 1.2 2012/10/03 18:28:29 asau Exp $

DISTNAME=	proggy-fonts-1
CATEGORIES=	fonts
MASTER_SITES=	http://dl.liveforge.org/fonts/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.proggyfonts.com/
COMMENT=	Set of monospaced bitmap programming fonts
LICENSE=	mit

WRKSRC=			${WRKDIR}/proggy-fonts
NO_BUILD=		yes
NO_CONFIGURE=		yes
USE_X11BASE=		yes

FONTS_DIRS.x11=		${PREFIX}/lib/X11/fonts/misc
INSTALLATION_DIRS=	lib/X11/fonts/misc
INSTALLATION_DIRS+=	share/doc/proggy-fonts

do-install:
	for i in ${WRKSRC}/*.pcf.gz; do \
		${INSTALL_DATA} $$i ${DESTDIR}${FONTS_DIRS.x11}; \
	done
	${INSTALL_DATA} ${WRKSRC}/Licence.txt \
		${DESTDIR}${PREFIX}/share/doc/proggy-fonts

.include "../../mk/bsd.pkg.mk"
