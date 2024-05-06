# $NetBSD: Makefile,v 1.3 2024/05/06 08:27:51 jperkin Exp $

DISTNAME=	dit-0.7
CATEGORIES=	editors
MASTER_SITES=	https://hisham.hm/dit/releases/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hisham.hm/dit/home.html
COMMENT=	Console text editor that you already know how to use
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
FAKE_NCURSES=	yes
USE_CURSES=	wide

CONFIGURE_ARGS+=	--with-lua-prefix=${_LUA_DOT_VERSION}

LUA_VERSIONS_ACCEPTED=	53 52 51

# when compiling with NetBSD curses:
# error: 'cchar_t' {aka 'struct <anonymous>'} has no member named 'chars'
.include "../../devel/ncurses/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
