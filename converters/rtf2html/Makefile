# $NetBSD: Makefile,v 1.4 2002/11/14 23:43:56 jlam Exp $
#

DISTNAME=	rtf2html
PKGNAME=	rtf2html-1.1
CATEGORIES=	converters
MASTER_SITES=	http://www.ice.ru/~vitus/misc/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ice.ru/~vitus/catdoc/
COMMENT=	Rich Text to HTML file converter

USE_BUILDLINK2=	# defined
ALL_TARGET=	rtf2html
MAKE_FLAGS+=	CFLAGS="${CFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rtf2html ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
