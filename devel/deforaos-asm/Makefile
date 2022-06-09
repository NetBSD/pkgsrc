# $NetBSD: Makefile,v 1.11 2022/06/09 07:44:49 wiz Exp $

DISTNAME=	Asm-0.2.6
PKGNAME=	deforaos-asm-0.2.6
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Devel/src/Asm/

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

.include "../../devel/deforaos-configure/deforaos-configure.mk"
.include "../../devel/deforaos-cpp/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk-doc+=	gtk-doc>=1.32nb9
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
