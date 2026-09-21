# $NetBSD: Makefile,v 1.48 2026/09/21 09:30:52 wiz Exp $

DISTNAME=	gnuchess-6.2.9
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU:=chess/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/chess/chess.html
COMMENT=	GNU chess engine
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	help2man-[0-9]*:../../converters/help2man

USE_LANGUAGES=		c c++
USE_TOOLS+=		flex gmake
GNU_CONFIGURE=		yes
INFO_FILES=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
