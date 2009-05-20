# $NetBSD: Makefile,v 1.16 2009/05/20 00:58:12 wiz Exp $
#

DISTNAME=	cgdb-0.4.0
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cgdb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cgdb.sourceforge.net/
COMMENT=	Curses-based interface to the GNU Debugger (GDB)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_NCURSES=	# tigetstr()
USE_GNU_READLINE=	# rl_mark and others

INSTALLATION_DIRS=	bin share/doc/cgdb

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cgdb/src/cgdb ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/cgdb

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
