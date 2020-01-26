# $NetBSD: Makefile,v 1.22 2020/01/26 17:30:40 rillig Exp $

DISTNAME=	lzop-1.04
CATEGORIES=	archivers
MASTER_SITES=	http://www.lzop.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.lzop.org/
COMMENT=	Fast file compressor similar to gzip, using the LZO library
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes

.include "../../archivers/lzo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
