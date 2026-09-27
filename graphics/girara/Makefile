# $NetBSD: Makefile,v 1.51 2026/09/27 11:36:44 tnn Exp $

DISTNAME=	girara-2026.02.04
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	https://pwmt.org/projects/girara/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	degroote@NetBSD.org
HOMEPAGE=	https://pwmt.org/projects/girara/
COMMENT=	Library to develop simple and minimalist user interface
LICENSE=	zlib

USE_TOOLS+=	gettext pkg-config

CFLAGS.SunOS+=	-D__EXTENSIONS__

PYTHON_FOR_BUILD_ONLY=	tool
USE_CC_FEATURES=	c17

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
