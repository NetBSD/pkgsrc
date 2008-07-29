# $NetBSD: Makefile,v 1.4.4.1 2008/07/29 11:58:48 rtr Exp $
#

DISTNAME=	newsx-1.6
PKGREVISION=	2
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.kvaleberg.com/pub/

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://www.kvaleberg.com/newsx.html
COMMENT=	NNTP news exchange program

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES

.include "../../news/inn/Makefile.common"
CONFIGURE_ARGS+=	--with-newshome=${INN_PREFIX}/lib
CONFIGURE_ARGS+=	--with-newsinclude=${PREFIX}/include/inn
CONFIGURE_ARGS+=	--with-rnews=${INN_PATHBIN}/rnews
CONFIGURE_ARGS+=	--with-inews=${INN_PATHBIN}/inews
CONFIGURE_ARGS+=	--with-history-mode=indexed

.include "../../news/inn/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
