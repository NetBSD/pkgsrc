# $NetBSD: Makefile,v 1.28 2020/03/20 11:57:26 nia Exp $

DISTNAME=	cgdb-0.6.8
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://cgdb.me/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cgdb.sourceforge.net/
COMMENT=	Curses-based interface to the GNU Debugger (GDB)
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	help2man-[0-9]*:../../converters/help2man

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake flex
INFO_FILES=	yes

# As -L/usr/lib tends to be found in LDFLAGS, make sure that the library
# of interest (the local libutil) is found first.
MAKE_ENV+=	AM_LDFLAGS=-L${WRKSRC}/lib/util/src

# rl_mark and others
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"

.if ${CURSES_TYPE} == "curses"
CONFIGURE_ARGS+=	--with-curses
.endif

.include "../../mk/bsd.pkg.mk"
