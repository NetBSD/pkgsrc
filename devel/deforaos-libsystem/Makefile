# $NetBSD: Makefile,v 1.8 2014/09/23 12:06:49 jperkin Exp $
#

DISTNAME=	libSystem-0.2.0
PKGNAME=	deforaos-libsystem-0.2.0
CATEGORIES=	devel
MASTER_SITES=	http://www.defora.org/os/download/download/4330/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS core system library

LICENSE=	gnu-lgpl-v3

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	INSTALL=${INSTALL}

REPLACE_SH=	tests/tests.sh

BUILDLINK_API_DEPENDS.gtk-doc+=	gtk-doc>=1.20
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
