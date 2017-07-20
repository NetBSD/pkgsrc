# $NetBSD: Makefile,v 1.11 2017/07/20 13:18:42 adam Exp $

DISTNAME=	orc-0.4.27
CATEGORIES=	devel
MASTER_SITES=	https://gstreamer.freedesktop.org/src/orc/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gstreamer.freedesktop.org/modules/orc.html
COMMENT=	Compiler for vector operations
LICENSE=	modified-bsd

USE_LIBTOOL=		yes
USE_TOOLS=		gmake
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	orc.pc.in
TEST_TARGET=		check

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
