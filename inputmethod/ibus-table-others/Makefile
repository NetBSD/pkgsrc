# $NetBSD: Makefile,v 1.10 2015/01/14 09:24:42 obache Exp $
#

DISTNAME=	ibus-table-others-1.3.7
CATEGORIES=	inputmethod
MASTER_SITES=	https://github.com/moebiuscurve/ibus-table-others/releases/download/${PKGVERSION_NOREV}/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus/
COMMENT=	All non-Chinese tables for IBus-Table
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	26 27
PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/application.mk"
.include "../../inputmethod/ibus-table/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
