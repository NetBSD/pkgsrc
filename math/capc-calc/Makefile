# $NetBSD: Makefile,v 1.49 2026/08/04 20:29:06 wiz Exp $
#

DISTNAME=	calc-2.12.7.1
PKGNAME=	capc-${DISTNAME:S/t/./}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=calc/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.isthe.com/chongo/tech/comp/calc/
COMMENT=	C arbitrary precision calculator

MAKE_JOBS_SAFE=	no

USE_TOOLS+=	gmake
BUILD_TARGET=	calc-static-only
MAKE_ENV+=	BLD_TYPE=calc-static-only target=pkgsrc
MAKE_ENV+=	DEBUG=${CFLAGS:M*:Q}

# XXX Doesn't use curses, but we patch for it for readline stupidly
FAKE_NCURSES=	yes

INSTALL_MAKE_FLAGS+=	T=${DESTDIR}

TEST_TARGET=	check

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
