# $NetBSD: Makefile,v 1.7 2006/04/28 18:35:06 joerg Exp $

DISTNAME=	qalculate-units-0.9.3
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qalculate/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://qalculate.sourceforge.net/
COMMENT=	Utility for conversion between units using Qalculate

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt pkg-config
GNU_CONFIGURE=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../math/qalculate/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
