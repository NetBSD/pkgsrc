# $NetBSD: Makefile,v 1.10 2017/12/24 10:04:36 wiz Exp $

DISTNAME=	newsx-1.6
PKGREVISION=	3
CATEGORIES=	news
#MASTER_SITES=	http://www.sfr-fresh.com/unix/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.kvaleberg.com/newsx.html
COMMENT=	NNTP news exchange program

GNU_CONFIGURE=		YES

.include "../../news/inn/Makefile.common"
CONFIGURE_ARGS+=	--with-newshome=${INN_PREFIX}/lib
CONFIGURE_ARGS+=	--with-newsinclude=${PREFIX}/include/inn
CONFIGURE_ARGS+=	--with-rnews=${INN_PATHBIN}/rnews
CONFIGURE_ARGS+=	--with-inews=${INN_PATHBIN}/inews
CONFIGURE_ARGS+=	--with-history-mode=indexed

MAKE_DIRS_PERMS+=	${INN_DATA_DIR}/inhosts ${INN_USER} ${INN_GROUP} 0775

.include "../../news/inn/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
