# $NetBSD: Makefile,v 1.32 2023/08/13 19:41:47 leot Exp $

DISTNAME=	less-643
CATEGORIES=	misc
MASTER_SITES=	http://www.greenwoodsoftware.com/less/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://www.greenwoodsoftware.com/less/
COMMENT=	Pager similar to more and pg
LICENSE=	2-clause-bsd OR gnu-gpl-v3

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

.include "options.mk"

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
