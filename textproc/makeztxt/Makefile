# $NetBSD: Makefile,v 1.7 2003/06/18 09:22:25 agc Exp $
#

DISTNAME=	${PKGNAME}b-src
PKGNAME=	makeztxt-1.40
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}b
CATEGORIES=	textproc converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gutenpalm/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://gutenpalm.sourceforge.net/makeztxt.php
COMMENT=	ASCII text to Palm zTXT database converter

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/makeztxt ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/makeztxt
.for doc in COPYING ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/makeztxt
.endfor

.include "../../mk/bsd.pkg.mk"
