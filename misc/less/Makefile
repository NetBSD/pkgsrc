# $NetBSD: Makefile,v 1.15 2006/09/27 11:28:32 taca Exp $
#

DISTNAME=       less-382
PKGREVISION=	1
CATEGORIES=     misc
MASTER_SITES=   http://www.greenwoodsoftware.com/less/ \
		${MASTER_SITE_GNU:=less/}

MAINTAINER=     bouyer@NetBSD.org
HOMEPAGE=       http://www.greenwoodsoftware.com/less/
COMMENT=	Pager similar to more and pg

GNU_CONFIGURE=  	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

.include "../../mk/bsd.pkg.mk"
