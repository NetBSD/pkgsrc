# $NetBSD: Makefile,v 1.2 2020/03/06 12:15:59 nia Exp $

DISTNAME=	hexcurse-1.60.0
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=LonnyGomes/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/LonnyGomes/hexcurse/
COMMENT=	Hexcurse is an ncurses-based console hexeditor written in C
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_NCURSES=	yes	# uses slk_* functions

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
