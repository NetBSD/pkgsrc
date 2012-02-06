# $NetBSD: Makefile,v 1.36 2012/02/06 12:40:16 wiz Exp $
#

DISTNAME=		aqsis-0.6.4
PKGREVISION=		9
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=aqsis/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.aqsis.org/
COMMENT=		Renderman clone
LICENSE=		gnu-gpl-v1

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake lex

GCC_REQD+=		2.95.3
USE_LANGUAGES=		c c++

.include "../../devel/libargparse/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
