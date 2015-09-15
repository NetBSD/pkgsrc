# $NetBSD: Makefile,v 1.5 2015/09/15 08:22:39 joerg Exp $

DISTNAME=	xeukleides.1.0.1
PKGNAME=	xeukleides-1.0.1
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://www.eukleides.org/download/

MAINTAINER=	tsadowski@gmx.net
HOMEPAGE=	http://www.eukleides.or/
COMMENT=	X-Frontend for A Euclidean geometry drawing language

MAKE_JOBS_SAFE=		no

DEPENDS+=	eukleides>=1.0.1<1.5:../../math/eukleides10

BUILD_TARGET=	xeukleides
USE_TOOLS+=	gmake flex bison

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
