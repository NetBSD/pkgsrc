# $NetBSD: Makefile,v 1.33 2010/01/04 16:05:57 joerg Exp $
#

DISTNAME=		aqsis-0.6.4
PKGREVISION=		7
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=aqsis/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.aqsis.com/
COMMENT=		Renderman clone

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
