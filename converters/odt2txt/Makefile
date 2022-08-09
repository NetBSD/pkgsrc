# $NetBSD: Makefile,v 1.9 2022/08/09 12:08:31 jperkin Exp $
#

DISTNAME=	odt2txt-0.5
CATEGORIES=	converters textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=dstosberg/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://github.com/dstosberg/odt2txt
COMMENT=	Simple converter from OpenDocument Text to plain text
LICENSE=	gnu-gpl-v2
GITHUB_TAG=	v${PKGVERSION_NOREV}

USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# TODO: iconv or not?
# TODO: maybe package odf2html, odfread, odfreader
