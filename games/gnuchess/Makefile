# $NetBSD: Makefile,v 1.45 2020/04/18 17:50:11 schwarz Exp $

DISTNAME=	gnuchess-6.2.6
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU:=chess/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/chess/chess.html
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
