# $NetBSD: Makefile,v 1.18 2024/08/25 06:18:55 wiz Exp $

DISTNAME=	ibus-table-chinese-1.8.12
CATEGORIES=	inputmethod chinese
MASTER_SITES=	${MASTER_SITE_GITHUB:=mike-fabian/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ibus/ibus/wiki
COMMENT=	Chinese tables for IBus-Table
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	pkg-config
CMAKE_CONFIGURE_ARGS+=	-DDATA_DIR=${PREFIX}/share

.include "../../inputmethod/ibus-table/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
