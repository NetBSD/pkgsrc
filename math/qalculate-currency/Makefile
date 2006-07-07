# $NetBSD: Makefile,v 1.13 2006/07/07 15:49:32 jlam Exp $

DISTNAME=	qalculate-currency-0.9.4
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qalculate/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://qalculate.sourceforge.net/
COMMENT=	Utility for conversion between currencies using Qalculate

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
GNU_CONFIGURE=		yes

.include "../../math/qalculate/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
