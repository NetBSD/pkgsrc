# $NetBSD: Makefile,v 1.3 2013/05/23 15:07:29 joerg Exp $
#

DISTNAME=		fish-1.23.1
CATEGORIES=		shells
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fish/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.fishshell.org/
COMMENT=		User friendly command line shell for UNIX-like operating systems
LICENSE=		gnu-gpl-v2

BUILD_DEPENDS+=		doxygen>=1.2.14:../../devel/doxygen

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--without-xsel
USE_TOOLS+=		gmake

EGDIR=			${PREFIX}/share/examples/fish
INSTALL_ENV+=		EGDIR=${EGDIR}

PKG_SHELL=		bin/fish

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && exists(/usr/include/execinfo.h)
CPPFLAGS+=		-DHAVE_BACKTRACE
CPPFLAGS+=		-DHAVE_BACKTRACE_SYMBOLS
LDFLAGS+=		-lexecinfo
.endif

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
