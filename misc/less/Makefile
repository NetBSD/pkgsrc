# $NetBSD: Makefile,v 1.31 2023/02/07 20:32:34 wiz Exp $

DISTNAME=	less-608
PKGREVISION=	1
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
