# $NetBSD: Makefile,v 1.16 2023/08/14 05:24:40 wiz Exp $
#

DISTNAME=	ibus-table-others-1.3.7
PKGREVISION=	2
CATEGORIES=	inputmethod
MASTER_SITES=	https://github.com/moebiuscurve/ibus-table-others/releases/download/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ibus/ibus/wiki
COMMENT=	All non-Chinese tables for IBus-Table
LICENSE=	gnu-gpl-v3

#FileExistsError: [Errno 17] File exists: '.../work/.home/.local/share/ibus-table'
MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/application.mk"
.include "../../inputmethod/ibus-table/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
