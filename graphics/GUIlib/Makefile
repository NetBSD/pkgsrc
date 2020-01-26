# $NetBSD: Makefile,v 1.21 2020/01/26 17:31:19 rillig Exp $
#

DISTNAME=	GUIlib-1.2.1
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.libsdl.org/projects/GUIlib/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.libsdl.org/projects/GUIlib/
COMMENT=	Very simple GUI framework library
LICENSE=	public-domain

GNU_CONFIGURE=		YES

USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
