# $NetBSD: Makefile,v 1.83 2026/09/02 19:02:12 wiz Exp $

DISTNAME=	holtz-1.5.0
PKGREVISION=	22
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=holtz/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://holtz.sourceforge.io/
COMMENT=	Engine for the abstract strategy games Zèrtz and Dvonn
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
FORCE_CXX_STD=		c++11

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../x11/wxGTK32/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
