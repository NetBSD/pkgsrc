# $NetBSD: Makefile,v 1.49 2026/03/02 13:28:36 yhardy Exp $

DISTNAME=	girara-2026.02.04
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
