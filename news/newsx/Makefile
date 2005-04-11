# $NetBSD: Makefile,v 1.3 2005/04/11 21:47:03 tv Exp $
#

DISTNAME=	newsx-1.6
PKGREVISION=	1
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.kvaleberg.com/pub/

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://www.kvaleberg.com/newsx.html
COMMENT=	NNTP news exchange program

GNU_CONFIGURE=		YES

.include "../../news/inn/Makefile.common"
CONFIGURE_ARGS+=	--with-newshome=${INN_PREFIX}/lib
CONFIGURE_ARGS+=	--with-rnews=${INN_PREFIX}/bin/rnews
CONFIGURE_ARGS+=	--with-inews=${INN_PREFIX}/bin/inews
CONFIGURE_ARGS+=	--with-history-mode=indexed

.include "../../news/inn/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
