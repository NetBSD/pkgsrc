# $NetBSD: Makefile,v 1.13 2018/10/04 19:03:23 leot Exp $

DISTNAME=	girara-0.3.1
CATEGORIES=	x11
MASTER_SITES=	https://pwmt.org/projects/girara/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	degroote@NetBSD.org
HOMEPAGE=	https://pwmt.org/projects/girara/
COMMENT=	Library to develop simple and minimalist user interface
LICENSE=	zlib

USE_TOOLS+=	gettext pkg-config

.include "../../devel/py-meson/build.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
