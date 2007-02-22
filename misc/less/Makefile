# $NetBSD: Makefile,v 1.16 2007/02/22 19:26:49 wiz Exp $
#

DISTNAME=	less-382
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.greenwoodsoftware.com/less/ \
		${MASTER_SITE_GNU:=less/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.greenwoodsoftware.com/less/
COMMENT=	Pager similar to more and pg

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

.include "../../mk/bsd.pkg.mk"
