# $NetBSD: Makefile,v 1.11 2005/12/11 09:40:44 wiz Exp $
#

DISTNAME=	GUIlib-1.1.0
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://www.libsdl.org/projects/GUIlib/src/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/GUIlib/
COMMENT=	Very simple GUI framework library

GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
