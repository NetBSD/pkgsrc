# $NetBSD: Makefile,v 1.15 2006/07/05 05:37:43 jlam Exp $

DISTNAME=	qalculate-gtk-0.9.4
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qalculate/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://qalculate.sourceforge.net/
COMMENT=	Qalculate is a modern multi-purpose desktop calculator

DEPENDS+=	gnuplot>=3.7:../../graphics/gnuplot
DEPENDS+=	wget>=1.8:../../net/wget

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
GNU_CONFIGURE=		yes

.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../math/qalculate/buildlink3.mk"
.include "../../textproc/scrollkeeper/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
