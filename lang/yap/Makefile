# $NetBSD: Makefile,v 1.10 2010/08/10 07:49:57 asau Exp $
#

DISTNAME=		yap-6.0.6
CATEGORIES=		lang
# MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=yap/}
MASTER_SITES=		http://www.dcc.fc.up.pt/~vsc/Yap/ \
			http://www.dcc.fc.up.pt/~vsc/Yap/current/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ncc.up.pt/~vsc/Yap/
COMMENT=		ISO-compliant Prolog

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			$(WRKDIR)/yap-6

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS=		gmake

# Don't enable system malloc, it dumps core otherwise:
#CONFIGURE_ARGS=		--enable-use-malloc
CONFIGURE_ENV+=		INDENT=${TRUE:Q}

# debug option:
#CONFIGURE_ARGS+=	--enable-debug-yap

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
