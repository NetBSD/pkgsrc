# $NetBSD: Makefile,v 1.12 2004/08/26 01:33:59 wiz Exp $
#

DISTNAME=       less-382
CATEGORIES=     misc
MASTER_SITES=   http://www.greenwoodsoftware.com/less/ \
		${MASTER_SITE_GNU:=less/}

MAINTAINER=     bouyer@NetBSD.org
HOMEPAGE=       http://www.greenwoodsoftware.com/less/
COMMENT=	Pager similar to more and pg

GNU_CONFIGURE=  	yes
USE_BUILDLINK3=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.pkg.mk"
