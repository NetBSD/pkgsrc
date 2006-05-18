# $NetBSD: Makefile,v 1.26 2006/05/18 20:29:59 wiz Exp $
#

DISTNAME=		aqsis-0.6.4
PKGREVISION=		6
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=aqsis/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.aqsis.com/
COMMENT=		Renderman clone

BROKEN_IN=		pkgsrc-2005Q4 pkgsrc-2006Q1

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_TOOLS+=		gmake

GCC_REQD+=		2.95.3
USE_LANGUAGES+=		c c++

.include "../../devel/libargparse/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
