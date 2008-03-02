# $NetBSD: Makefile,v 1.19 2008/03/02 15:35:33 bjs Exp $
#

DISTNAME=	less-418
CATEGORIES=	misc
MASTER_SITES=	http://www.greenwoodsoftware.com/less/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.greenwoodsoftware.com/less/
COMMENT=	Pager similar to more and pg

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

.include "options.mk"

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
