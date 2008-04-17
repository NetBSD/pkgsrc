# $NetBSD: Makefile,v 1.1.1.1 2008/04/17 12:33:56 reed Exp $
#

DISTNAME=	odt2txt-0.3
CATEGORIES=	converters textproc
MASTER_SITES=	http://stosberg.net/odt2txt/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://stosberg.net/odt2txt/
COMMENT=	Simple converter from OpenDocument Text to plain text

USE_TOOLS+=	gmake
MAKE_ENV+=	DESTDIR="${LOCALBASE}" MANDIR="/${PKGMANDIR}"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# TODO: maybe -m 644 for install of man page
# TODO: iconv or not?
# TODO: maybe package odf2html, odfread, odfreader
