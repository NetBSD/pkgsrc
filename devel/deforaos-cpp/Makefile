# $NetBSD: Makefile,v 1.2 2016/02/23 00:30:27 khorben Exp $
#

DISTNAME=	CPP-0.0.3
PKGNAME=	deforaos-cpp-0.0.3
PKGREVISION=	1
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

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/cpp ${DESTDIR}${PREFIX}/bin/deforaos-cpp

.include "../../devel/deforaos-libsystem/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk-doc+=	gtk-doc>=1.20
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
