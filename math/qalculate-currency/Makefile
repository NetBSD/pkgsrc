# $NetBSD: Makefile,v 1.10 2006/06/16 14:35:27 joerg Exp $

DISTNAME=	qalculate-currency-0.9.4
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qalculate/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://qalculate.sourceforge.net/
COMMENT=	Utility for conversion between currencies using Qalculate

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake msgfmt pkg-config
GNU_CONFIGURE=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

BUILD_DEPENDS+=		p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

.include "../../math/qalculate/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
