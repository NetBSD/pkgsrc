# $NetBSD: Makefile,v 1.33 2024/08/03 13:38:25 pin Exp $

DISTNAME=	less-661
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
