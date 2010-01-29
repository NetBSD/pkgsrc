# $NetBSD: Makefile,v 1.2 2010/01/29 16:47:52 joerg Exp $
#

DISTNAME=	odt2txt-0.3
CATEGORIES=	converters textproc
MASTER_SITES=	http://stosberg.net/odt2txt/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://stosberg.net/odt2txt/
COMMENT=	Simple converter from OpenDocument Text to plain text

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# TODO: iconv or not?
# TODO: maybe package odf2html, odfread, odfreader
