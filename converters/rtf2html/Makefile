# $NetBSD: Makefile,v 1.3 2001/11/02 18:16:46 wiz Exp $
#

DISTNAME=	rtf2html
PKGNAME=	rtf2html-1.1
CATEGORIES=	converters
MASTER_SITES=	http://www.ice.ru/~vitus/misc/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ice.ru/~vitus/catdoc/
COMMENT=	Rich Text to HTML file converter

USE_BUILDLINK_ONLY=	# defined
ALL_TARGET=		rtf2html
MAKE_FLAGS+=		CC="${CC}"
MAKE_FLAGS+=		CFLAGS="${CFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rtf2html ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
