# $NetBSD: Makefile,v 1.8 2021/05/24 19:52:03 wiz Exp $

DISTNAME=	stfl-0.24
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	http://www.clifford.at/stfl/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.clifford.at/stfl/
COMMENT=	Library which implements a curses-based widget set for text terminals
LICENSE=	gnu-lgpl-v3

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake perl
USE_LIBTOOL=	yes
USE_CURSES=	wide

INSTALL_MAKE_FLAGS+=	prefix=${PREFIX}

MAKE_ENV+=	CURSES_LIB=${BUILDLINK_LDADD.curses}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
