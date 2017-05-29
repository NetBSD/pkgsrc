# $NetBSD: Makefile,v 1.26 2017/05/29 11:09:46 jperkin Exp $

DISTNAME=		yap-6.3.3
PKGREVISION=		5
CATEGORIES=		lang
# MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=yap/}
MASTER_SITES=		http://www.dcc.fc.up.pt/~vsc/Yap/
MASTER_SITES+=		http://www.dcc.fc.up.pt/~vsc/Yap/current/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ncc.up.pt/~vsc/Yap/
COMMENT=		ISO-compliant Prolog

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS=		gmake

CONFIGURE_ENV+=		INDENT=${TRUE:Q}

# debug option:
#CONFIGURE_ARGS+=	--enable-debug-yap

.include "../../mk/bsd.prefs.mk"

# If it doesn't probe a c++0x compiler, it doesn't build "horus",
# which is apparently a belief propagation engine. There isn't any
# good way to detect in pkgsrc if the current compiler supports any
# particular dialect (at least as of this writing) and forcing a
# non-default compiler seems like overkill, so for now at least we'll
# approximate by OS.
PLIST_VARS+=		horus
.if ${OPSYS} != "OpenBSD"
PLIST.horus=		yes
.endif

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
