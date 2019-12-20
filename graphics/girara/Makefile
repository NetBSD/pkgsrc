# $NetBSD: Makefile,v 1.20 2019/12/20 10:11:55 leot Exp $

DISTNAME=	girara-0.3.3
CATEGORIES=	x11
MASTER_SITES=	https://pwmt.org/projects/girara/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	degroote@NetBSD.org
HOMEPAGE=	https://pwmt.org/projects/girara/
COMMENT=	Library to develop simple and minimalist user interface
LICENSE=	zlib

USE_TOOLS+=	gettext pkg-config

CFLAGS.SunOS+=	-D__EXTENSIONS__

.include "../../devel/meson/build.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
