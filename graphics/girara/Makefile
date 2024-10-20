# $NetBSD: Makefile,v 1.42 2024/10/20 14:03:57 wiz Exp $

DISTNAME=	girara-0.4.4
PKGREVISION=	1
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

.include "../../devel/meson/build.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
