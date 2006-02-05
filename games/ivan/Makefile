# $NetBSD: Makefile,v 1.7 2006/02/05 23:09:16 joerg Exp $
#

DISTNAME=		ivan-0.50
PKGREVISION=		3
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
