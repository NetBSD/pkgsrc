# $NetBSD: Makefile,v 1.13 2022/10/17 00:19:00 khorben Exp $

DISTNAME=	Asm-0.2.7
PKGNAME=	deforaos-asm-0.2.7
CATEGORIES=	devel
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Devel/src/Asm/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	DeforaOS (dis)assembly framework
LICENSE=	gnu-lgpl-v3

USE_TOOLS+=	pkg-config

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=	INSTALL=${INSTALL}
AUTO_MKDIRS=	yes

.include "../../devel/deforaos-configure/deforaos-configure.mk"
.include "../../devel/deforaos-cpp/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk-doc+=	gtk-doc>=1.32nb9
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
