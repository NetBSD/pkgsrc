# $NetBSD: Makefile,v 1.1.1.1 2001/05/14 13:36:21 agc Exp $
#

DISTNAME=	rtf2html
PKGNAME=	rtf2html-1.1
CATEGORIES=	converters
MASTER_SITES=	http://www.fe.msk.ru/~vitus/misc/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.fe.msk.ru/~vitus/catdoc/
COMMENT=	Rich Text to HTML file converter

ALL_TARGET=	rtf2html

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rtf2html ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
