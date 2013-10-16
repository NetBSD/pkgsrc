# $NetBSD: Makefile,v 1.23 2013/10/16 10:51:39 roy Exp $

DISTNAME=	cgdb-0.6.5
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cgdb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cgdb.sourceforge.net/
COMMENT=	Curses-based interface to the GNU Debugger (GDB)
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

MAKE_ENV+=	AM_LDFLAGS=-L${WRKSRC}/various/util/src

INSTALLATION_DIRS=	bin share/doc/cgdb

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cgdb/src/cgdb ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/cgdb

# rl_mark and others
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

.if ${CURSES_TYPE} == "curses"
CONFIGURE_ARGS+=	--with-curses
.endif
