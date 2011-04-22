# $NetBSD: Makefile,v 1.20 2011/04/22 13:44:08 obache Exp $

DISTNAME=	xeukleides.1.0.1
PKGNAME=	xeukleides-1.0.1
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.eukleides.org/download/

MAINTAINER=	tsadowski@gmx.net
HOMEPAGE=	http://www.eukleides.or/
COMMENT=	X-Frontend for A Euclidean geometry drawing language

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

DEPENDS+=	eukleides>=1.0.1:../../math/eukleides

USE_X11BASE=	yes
BUILD_TARGET=	xeukleides
USE_TOOLS+=	gmake flex bison

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
