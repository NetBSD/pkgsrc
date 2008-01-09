# $NetBSD: Makefile,v 1.2 2008/01/09 13:40:37 heinz Exp $
#

DISTNAME=	rlwrap-0.30
CATEGORIES=	misc
MASTER_SITES=	http://utopia.knoware.nl/~hlub/uck/rlwrap/

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://utopia.knoware.nl/~hlub/uck/rlwrap/
COMMENT=	Provides command line editing and history for other commands

#LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_API_DEPENDS.readline+=readline>=4.2

GNU_CONFIGURE=		yes

.include "options.mk"

USE_GNU_READLINE=	yes
USE_LANGUAGES=		c
USE_TOOLS+=		gmake

TEST_TARGET=		check

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
