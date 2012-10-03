# $NetBSD: Makefile,v 1.3 2012/10/03 21:57:46 wiz Exp $

DISTNAME=		c2html-20070126
PKGREVISION=		1
CATEGORIES=		textproc devel
MASTER_SITES=		http://gavare.se/c2html/src/

MAINTAINER=		lkundrak@skosi.org
HOMEPAGE=		http://gavare.se/c2html/
COMMENT=		Converts a C source tree to hyperlinked and colored HTML

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PREFIX}/share/doc/${PKGBASE}

do-install:
	${INSTALL_PROGRAM}	${WRKSRC}/c2html ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA}		${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
