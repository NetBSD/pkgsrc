# $NetBSD: Makefile,v 1.4 2005/02/01 16:16:16 adam Exp $

DISTNAME=	qalculate-0.7.2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qalculate/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://qalculate.sourceforge.net/
COMMENT=	Qalculate is a modern multi-purpose desktop calculator

DEPENDS+=	gnuplot>=3.7:../../graphics/gnuplot
DEPENDS+=	wget>=1.8:../../net/wget

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_READLINE=	yes
GNU_CONFIGURE=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/src/libqalculate/libqalculate.pc.in

UNLIMIT_RESOURCES=	datasize

.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../math/cln/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
