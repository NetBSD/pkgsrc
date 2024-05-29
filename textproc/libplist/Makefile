# $NetBSD: Makefile,v 1.40 2024/05/29 16:34:37 adam Exp $

DISTNAME=	libplist-2.2.0
PKGREVISION=	6
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=libimobiledevice/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.libimobiledevice.org/
COMMENT=	Handle Apple Binary and XML Property Lists
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
CONFIG_SHELL=	bash
USE_TOOLS+=	bash gmake pkg-config
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=		libplist++.pc.in
PKGCONFIG_OVERRIDE+=		libplist.pc.in
PY_PATCHPLIST=			yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/py-cython/buildlink3.mk"
.include "../../devel/py-cython/tool.mk"
.include "../../lang/python/extension.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
