# $NetBSD: Makefile,v 1.30 2024/05/08 12:08:44 jperkin Exp $

DISTNAME=	cgdb-0.7.1
CATEGORIES=	devel
MASTER_SITES=	http://cgdb.me/files/

MAINTAINER=	kamil@NetBSD.org
HOMEPAGE=	http://cgdb.sourceforge.net/
COMMENT=	Curses-based interface to the GNU Debugger (GDB)
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake flex
INFO_FILES=	yes

# As -L/usr/lib tends to be found in LDFLAGS, make sure that the library
# of interest (the local libutil) is found first.
MAKE_ENV+=	AM_LDFLAGS=-L${WRKSRC}/lib/util/src

# Doesn't detect builtin curses correctly, redefines COLOR_*, etc.
.include "../../devel/ncurses/buildlink3.mk"

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
