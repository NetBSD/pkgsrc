# $NetBSD: Makefile,v 1.8 2004/04/11 07:44:14 snj Exp $
#

DISTNAME=	rtf2html
PKGNAME=	rtf2html-1.1
CATEGORIES=	converters
MASTER_SITES=	http://www.45.free.net/~vitus/ice/misc/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.45.free.net/~vitus/ice/catdoc/
COMMENT=	Rich Text to HTML file converter

USE_BUILDLINK3=	# defined
ALL_TARGET=	rtf2html
MAKE_FLAGS+=	CFLAGS="${CFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rtf2html ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
