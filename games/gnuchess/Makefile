# $NetBSD: Makefile,v 1.43 2017/08/18 22:14:38 adam Exp $

DISTNAME=	gnuchess-6.2.5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU:=chess/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/chess/chess.html
COMMENT=	GNU chess engine
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c c++
USE_TOOLS+=		flex gmake
GNU_CONFIGURE=		yes
INFO_FILES=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
