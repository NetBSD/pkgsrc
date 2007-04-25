# $NetBSD: Makefile,v 1.17 2007/04/25 18:06:51 tnn Exp $
#

DISTNAME=	less-394
CATEGORIES=	misc
MASTER_SITES=	http://www.greenwoodsoftware.com/less/ \
		${MASTER_SITE_GNU:=less/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.greenwoodsoftware.com/less/
COMMENT=	Pager similar to more and pg

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

.include "../../mk/bsd.pkg.mk"
