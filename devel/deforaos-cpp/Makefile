# $NetBSD: Makefile,v 1.1 2016/02/20 02:54:45 khorben Exp $
#

DISTNAME=	CPP-0.0.3
PKGNAME=	deforaos-cpp-0.0.3
CATEGORIES=	devel
MASTER_SITES=	http://www.defora.org/os/download/download/4422/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS C code pre-processing library

LICENSE=	gnu-lgpl-v3

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=	INSTALL=${INSTALL}
AUTO_MKDIRS=	yes

.include "../../devel/deforaos-libsystem/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk-doc+=	gtk-doc>=1.20
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
