# $NetBSD: Makefile,v 1.1.1.1 2010/08/07 02:18:29 obache Exp $
#

DISTNAME=	ibus-table-chinese-1.3.0.20100527
CATEGORIES=	inputmethod chinese
MASTER_SITES=	http://ibus.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ibus/
COMMENT=	Chinese tables for IBus-Table
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--enable-extra-phrases

.include "../../inputmethod/ibus-table-extraphrase/buildlink3.mk"
.include "../../inputmethod/ibus-table/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
