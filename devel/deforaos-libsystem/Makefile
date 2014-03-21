# $NetBSD: Makefile,v 1.6 2014/03/21 13:57:42 jperkin Exp $
#

DISTNAME=	libSystem-0.1.7
PKGNAME=	deforaos-libsystem-0.1.7
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.defora.org/os/download/download/4321/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS core system library

LICENSE=	gnu-lgpl-v3

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	INSTALL=${INSTALL}

BUILDLINK_API_DEPENDS.gtk-doc+=	gtk-doc>=1.20
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
