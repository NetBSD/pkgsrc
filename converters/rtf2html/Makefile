# $NetBSD: Makefile,v 1.5 2003/06/02 01:21:15 jschauma Exp $
#

DISTNAME=	rtf2html
PKGNAME=	rtf2html-1.1
CATEGORIES=	converters
MASTER_SITES=	http://www.ice.ru/~vitus/misc/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.ice.ru/~vitus/catdoc/
COMMENT=	Rich Text to HTML file converter

USE_BUILDLINK2=	# defined
ALL_TARGET=	rtf2html
MAKE_FLAGS+=	CFLAGS="${CFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rtf2html ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
