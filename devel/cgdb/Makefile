# $NetBSD: Makefile,v 1.20 2011/09/08 19:46:30 wiz Exp $

DISTNAME=	cgdb-0.6.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cgdb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cgdb.sourceforge.net/
COMMENT=	Curses-based interface to the GNU Debugger (GDB)
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_NCURSES=	yes # tigetstr()
USE_GNU_READLINE=	yes # rl_mark and others

MAKE_ENV+=	AM_LDFLAGS=-L${WRKSRC}/various/util/src

INSTALLATION_DIRS=	bin share/doc/cgdb

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cgdb/src/cgdb ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/cgdb

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
