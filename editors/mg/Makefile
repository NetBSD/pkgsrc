# $NetBSD: Makefile,v 1.6 2012/10/11 13:03:38 marino Exp $
#

DISTNAME=	mg-20090107
CATEGORIES=	editors
MASTER_SITES=	http://www.dds.nl/~han/software/mg/

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.han.dds.nl/software/mg/
COMMENT=	Small, fast, public domain EMACS style editor

HAS_CONFIGURE=	yes
USE_NCURSES=	yes # Uses NCURSES internals
MAKE_ENV+=	prefix=${PREFIX}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

CONFLICTS+=	mg2a-[0-9]*

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
