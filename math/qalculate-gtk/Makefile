# $NetBSD: Makefile,v 1.2 2005/10/11 12:36:50 adam Exp $

DISTNAME=	qalculate-gtk-0.8.2
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

.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../math/qalculate/buildlink3.mk"
.include "../../textproc/scrollkeeper/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
