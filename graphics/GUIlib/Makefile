# $NetBSD: Makefile,v 1.3 2003/05/02 11:55:07 wiz Exp $
#

DISTNAME=	GUIlib-1.1.0
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.libsdl.org/projects/GUIlib/src/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.libsdl.org/projects/GUIlib/
COMMENT=	very simple GUI framework library

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
