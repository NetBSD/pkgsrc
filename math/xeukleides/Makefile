# $NetBSD: Makefile,v 1.18 2008/09/02 05:33:32 obache Exp $

DISTNAME=	xeukleides.1.0.1
PKGNAME=	xeukleides-1.0.1
CATEGORIES=	math
MASTER_SITES=	http://www.eukleides.org/download/

MAINTAINER=	tsadowski@gmx.net
HOMEPAGE=	http://www.eukleides.or/
COMMENT=	X-Frontend for A Euclidean geometry drawing language

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	eukleides>=1.0.1:../../math/eukleides

USE_X11BASE=	yes
BUILD_TARGET=	xeukleides
USE_TOOLS+=	gmake flex bison

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
