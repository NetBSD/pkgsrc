# $NetBSD: Makefile,v 1.5 2005/04/11 21:45:51 tv Exp $
#

DISTNAME=		ivan-0.50
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ivan/}

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://ivan.sourceforge.net/
COMMENT=		Graphical roguelike featuring deep gameplay

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--localstatedir=${PREFIX}/share

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
