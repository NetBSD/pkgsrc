# $NetBSD: Makefile,v 1.6 2020/03/16 13:18:44 wiz Exp $

DISTNAME=	CPP-0.0.3
PKGNAME=	deforaos-cpp-0.0.3
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	https://www.defora.org/os/download/download/4422/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
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
