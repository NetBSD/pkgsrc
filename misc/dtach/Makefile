# $NetBSD: Makefile,v 1.1.1.1 2006/06/17 14:26:47 minskim Exp $

DISTNAME=	dtach-0.7
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dtach/}

MAINTAINER=	fgudin@nerim.net
HOMEPAGE=	http://dtach.sourceforge.net/
COMMENT=	Small program that emulates the detach feature of screen

GNU_CONFIGURE=	yes
BUILD_TARGET=	dtach

DOCS=		COPYING README dtach.spec

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/dtach ${PREFIX:Q}/bin
	${INSTALL_MAN} ${WRKSRC:Q}/dtach.1 ${PREFIX:Q}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/doc/${PKGBASE:Q}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC:Q}/${f:Q} ${PREFIX:Q}/share/doc/${PKGBASE:Q}
.endfor

.include "../../mk/bsd.pkg.mk"
