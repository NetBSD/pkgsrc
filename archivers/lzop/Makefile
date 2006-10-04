# $NetBSD: Makefile,v 1.16 2006/10/04 20:45:46 wiz Exp $
#

DISTNAME=	lzop-1.01
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://www.lzop.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lzop.org/
COMMENT=	Fast file compressor similar to gzip, using the LZO library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	YES

.include "../../archivers/liblzo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
