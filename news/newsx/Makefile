# $NetBSD: Makefile,v 1.1.1.1 2003/12/31 13:28:36 cube Exp $
#

DISTNAME=	newsx-1.6
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.kvaleberg.com/pub/

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://www.kvaleberg.com/newsx.html
COMMENT=	NNTP news exchange program

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES

.include "../../news/inn/Makefile.common"
CONFIGURE_ARGS+=	--with-newshome=${INN_PREFIX}/lib
CONFIGURE_ARGS+=	--with-rnews=${INN_PREFIX}/bin/rnews
CONFIGURE_ARGS+=	--with-inews=${INN_PREFIX}/bin/inews

.include "../../news/inn/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
