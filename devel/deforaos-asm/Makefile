# $NetBSD: Makefile,v 1.3 2019/09/27 09:29:44 wiz Exp $

DISTNAME=	Asm-0.2.3
PKGNAME=	deforaos-asm-0.2.3
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://www.defora.org/os/download/download/4423/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	DeforaOS (dis)assembly framework
LICENSE=	gnu-lgpl-v3

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=	INSTALL=${INSTALL}
AUTO_MKDIRS=	yes

.include "../../devel/deforaos-cpp/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk-doc+=	gtk-doc>=1.20
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
