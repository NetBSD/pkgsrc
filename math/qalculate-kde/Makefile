# $NetBSD: Makefile,v 1.3 2006/01/24 07:32:20 wiz Exp $

DISTNAME=	qalculate-kde-0.8.2
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qalculate/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://qalculate.sourceforge.net/
COMMENT=	Qalculate is a modern multi-purpose desktop calculator

DEPENDS+=	gnuplot>=3.7:../../graphics/gnuplot
DEPENDS+=	wget>=1.8:../../net/wget

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/kde

.include "../../math/qalculate/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
