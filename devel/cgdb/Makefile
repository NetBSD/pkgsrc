# $NetBSD: Makefile,v 1.4 2004/10/03 00:13:25 tv Exp $
#

DISTNAME=	cgdb-0.4.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cgdb/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://cgdb.sourceforge.net/
COMMENT=	Curses-based interface to the GNU Debugger (GDB)

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make
USE_NCURSES=	# tigetstr()
USE_GNU_READLINE=	# rl_mark and others

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cgdb
	${INSTALL_PROGRAM} ${WRKSRC}/cgdb/src/cgdb ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cgdb

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
