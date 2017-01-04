# $NetBSD: Makefile,v 1.18 2017/01/04 01:49:41 roy Exp $
#

DISTNAME=	bmon-3.8
CATEGORIES=	net
MASTER_SITES=	https://github.com/tgraf/
LICENSE=	mit AND 2-clause-bsd
GITHUB_RELEASE=	v3.8

MAINTAINER=	hsaliak@gmail.com
HOMEPAGE=	https://github.com/tgraf/bmon
COMMENT=	Interface bandwidth monitor

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

.include "../../devel/confuse/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/fetch/github.mk"
.include "../../mk/bsd.pkg.mk"
