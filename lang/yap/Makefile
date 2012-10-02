# $NetBSD: Makefile,v 1.14 2012/10/02 20:11:57 asau Exp $
#

DISTNAME=		yap-6.2.2
CATEGORIES=		lang
# MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=yap/}
MASTER_SITES=		http://www.dcc.fc.up.pt/~vsc/Yap/ \
			http://www.dcc.fc.up.pt/~vsc/Yap/current/

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

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
