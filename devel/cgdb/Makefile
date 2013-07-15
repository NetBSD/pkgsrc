# $NetBSD: Makefile,v 1.22 2013/07/15 02:02:20 ryoon Exp $

DISTNAME=	cgdb-0.6.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cgdb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cgdb.sourceforge.net/
COMMENT=	Curses-based interface to the GNU Debugger (GDB)
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_NCURSES=	yes # tigetstr()

MAKE_ENV+=	AM_LDFLAGS=-L${WRKSRC}/various/util/src

INSTALLATION_DIRS=	bin share/doc/cgdb

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cgdb/src/cgdb ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/cgdb

# rl_mark and others
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
