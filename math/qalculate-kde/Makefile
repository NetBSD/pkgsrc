# $NetBSD: Makefile,v 1.10 2006/07/20 12:32:02 joerg Exp $

DISTNAME=	qalculate-kde-0.9.4
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qalculate/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://qalculate.sourceforge.net/
COMMENT=	Qalculate is a modern multi-purpose desktop calculator

DEPENDS+=	gnuplot>=3.7:../../graphics/gnuplot
DEPENDS+=	wget>=1.8:../../net/wget

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake msgfmt pkg-config perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/kde

.include "../../math/qalculate/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
