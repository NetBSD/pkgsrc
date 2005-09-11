# $NetBSD: Makefile,v 1.8 2005/09/11 17:01:14 minskim Exp $

DISTNAME=	libqalculate-0.8.1.1
PKGNAME=	qalculate-0.8.1.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qalculate/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://qalculate.sourceforge.net/
COMMENT=	Qalculate is a modern multi-purpose desktop calculator

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
USE_GNU_READLINE=	yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/src/libqalculate/libqalculate.pc.in

UNLIMIT_RESOURCES=	datasize

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../math/cln/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
