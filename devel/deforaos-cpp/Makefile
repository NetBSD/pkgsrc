# $NetBSD: Makefile,v 1.11 2022/06/07 07:37:58 wiz Exp $

DISTNAME=	CPP-0.0.6
PKGNAME=	deforaos-cpp-0.0.6
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Devel/src/CPP/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	DeforaOS C code pre-processing library
LICENSE=	gnu-lgpl-v3

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	CPPFLAGS=-DPROGNAME_CPP=\\\"deforaos-cpp\\\"
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=	INSTALL=${INSTALL}

MAKE_JOBS_SAFE=	no

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/cpp ${DESTDIR}${PREFIX}/bin/deforaos-cpp

.include "../../devel/deforaos-configure/deforaos-configure.mk"
.include "../../devel/deforaos-libsystem/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk-doc+=	gtk-doc>=1.32nb9
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
