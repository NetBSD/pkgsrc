# $NetBSD: Makefile,v 1.8 2001/01/31 16:10:13 wiz Exp $

DISTNAME=	unrar-2.71
CATEGORIES=	archivers
MASTER_SITES=	ftp://sunsite.univie.ac.at/pub/distfiles/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.rarsoft.com/

do-build:
	cd ${WRKSRC} && ${LINK.c} -o unrar -D_UNIX unrar.c

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/unrar
	cd ${WRKSRC} && ${INSTALL_PROGRAM} unrar ${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_MAN} readme.txt license.txt \
		${PREFIX}/share/doc/unrar

.include "../../mk/bsd.pkg.mk"
