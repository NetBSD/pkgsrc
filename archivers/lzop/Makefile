# $NetBSD: Makefile,v 1.21 2018/01/29 14:47:53 mef Exp $

DISTNAME=	lzop-1.04
CATEGORIES=	archivers
MASTER_SITES=	http://www.lzop.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lzop.org/
COMMENT=	Fast file compressor similar to gzip, using the LZO library
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes

.include "../../archivers/lzo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
