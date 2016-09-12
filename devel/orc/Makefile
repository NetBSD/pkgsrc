# $NetBSD: Makefile,v 1.10 2016/09/12 09:11:48 wiz Exp $

DISTNAME=	orc-0.4.26
CATEGORIES=	devel
MASTER_SITES=	https://gstreamer.freedesktop.org/src/orc/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gstreamer.freedesktop.org/modules/orc.html
COMMENT=	Compiler for vector operations
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	gmake

PKGCONFIG_OVERRIDE+=	orc.pc.in
TEST_TARGET=	check

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
