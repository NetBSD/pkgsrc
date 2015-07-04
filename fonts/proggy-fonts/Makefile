# $NetBSD: Makefile,v 1.4 2015/07/04 16:18:33 joerg Exp $

DISTNAME=	proggy-fonts-1
PKGREVISION=	1
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

FONTS_DIRS.x11=		${PREFIX}/share/fonts/X11/misc
INSTALLATION_DIRS=	share/fonts/X11/misc
INSTALLATION_DIRS+=	share/doc/proggy-fonts

do-install:
	for i in ${WRKSRC}/*.pcf.gz; do \
		${INSTALL_DATA} $$i ${DESTDIR}${FONTS_DIRS.x11}; \
	done
	${INSTALL_DATA} ${WRKSRC}/Licence.txt \
		${DESTDIR}${PREFIX}/share/doc/proggy-fonts

.include "../../mk/bsd.pkg.mk"
