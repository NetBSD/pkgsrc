# $NetBSD: Makefile,v 1.18 2011/03/17 14:57:47 adam Exp $

DISTNAME=	lzop-1.03
CATEGORIES=	archivers
MASTER_SITES=	http://www.lzop.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lzop.org/
COMMENT=	Fast file compressor similar to gzip, using the LZO library
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

.include "../../archivers/lzo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
