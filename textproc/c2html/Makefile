# $NetBSD: Makefile,v 1.14 2022/06/28 11:36:08 wiz Exp $

DISTNAME=		c2html-20070126
PKGREVISION=		10
CATEGORIES=		textproc devel
#MASTER_SITES=		http://gavare.se/c2html/src/

MAINTAINER=		lkundrak@skosi.org
#HOMEPAGE=		http://gavare.se/c2html/
COMMENT=		Converts a C source tree to hyperlinked and colored HTML

INSTALLATION_DIRS=	bin ${PREFIX}/share/doc/${PKGBASE}

do-install:
	${INSTALL_PROGRAM}	${WRKSRC}/c2html ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA}		${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
