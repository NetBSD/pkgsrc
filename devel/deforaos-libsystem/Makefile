# $NetBSD: Makefile,v 1.1 2012/12/16 23:55:22 khorben Exp $
#

DISTNAME=	libSystem-0.1.5
PKGNAME=	deforaos-libsystem-0.1.5
CATEGORIES=	devel
MASTER_SITES=	http://www.defora.org/os/download/download/3450/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS core system library

LICENSE=	gnu-gpl-v3

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
