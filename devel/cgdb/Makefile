# $NetBSD: Makefile,v 1.7 2005/06/16 06:57:45 jlam Exp $
#

DISTNAME=	cgdb-0.4.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cgdb/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://cgdb.sourceforge.net/
COMMENT=	Curses-based interface to the GNU Debugger (GDB)

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_NCURSES=	# tigetstr()
USE_GNU_READLINE=	# rl_mark and others

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cgdb
	${INSTALL_PROGRAM} ${WRKSRC}/cgdb/src/cgdb ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cgdb

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
