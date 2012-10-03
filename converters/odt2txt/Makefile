# $NetBSD: Makefile,v 1.6 2012/10/03 00:20:12 asau Exp $
#

DISTNAME=	odt2txt-0.4
PKGREVISION=	1
CATEGORIES=	converters textproc
MASTER_SITES=	http://stosberg.net/odt2txt/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://stosberg.net/odt2txt/
COMMENT=	Simple converter from OpenDocument Text to plain text
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

LDFLAGS.SunOS+=	-liconv

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# TODO: iconv or not?
# TODO: maybe package odf2html, odfread, odfreader
