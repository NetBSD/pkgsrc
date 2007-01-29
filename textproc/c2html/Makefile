# $NetBSD: Makefile,v 1.1.1.1 2007/01/29 16:40:58 minskim Exp $

DISTNAME=		c2html-20070126
CATEGORIES=		textproc devel
MASTER_SITES=		http://gavare.se/c2html/src/

MAINTAINER=		lkundrak@skosi.org
HOMEPAGE=		http://gavare.se/c2html/
COMMENT=		Converts a C source tree to hyperlinked and colored HTML

INSTALLATION_DIRS=	bin ${PREFIX}/share/doc/${PKGBASE}

do-install:
	${INSTALL_PROGRAM}	${WRKSRC}/c2html ${PREFIX}/bin
	${INSTALL_DATA}		${WRKSRC}/README ${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
