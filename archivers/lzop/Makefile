# $NetBSD: Makefile,v 1.19 2012/09/11 19:46:57 asau Exp $

DISTNAME=	lzop-1.03
CATEGORIES=	archivers
MASTER_SITES=	http://www.lzop.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lzop.org/
COMMENT=	Fast file compressor similar to gzip, using the LZO library
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes

.include "../../archivers/lzo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
