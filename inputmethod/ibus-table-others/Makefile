# $NetBSD: Makefile,v 1.2 2010/08/11 12:32:00 obache Exp $
#

DISTNAME=	ibus-table-others-1.3.0.20100528
CATEGORIES=	inputmethod
MASTER_SITES=	http://ibus.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus/
COMMENT=	All non-Chinese tables for IBus-Table
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	pkg-config

PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/application.mk"
.include "../../inputmethod/ibus-table/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
