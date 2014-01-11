# $NetBSD: Makefile,v 1.4 2014/01/11 20:53:15 khorben Exp $
#

DISTNAME=	libSystem-0.1.7
PKGNAME=	deforaos-libsystem-0.1.7
CATEGORIES=	devel
MASTER_SITES=	http://www.defora.org/os/download/download/4321/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS core system library

LICENSE=	gnu-lgpl-v3

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	INSTALL=${INSTALL}

.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
