# $NetBSD: Makefile,v 1.3 1998/12/28 20:24:48 tron Exp $
#

DISTNAME=	pspp-0.2.0
CATEGORIES=	math
MASTER_SITES=	ftp://franz.stat.wisc.edu/pub/PSPP/ \
		ftp://alpha.gnu.org/gnu/pspp/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/pspp/

DEPENDS+=	gettext-0.10.35:../../devel/gettext
DEPENDS+=	readline-2.2:../../devel/readline
DEPENDS+=	ncurses-1.9.9g:../../devel/ncurses

GNU_CONFIGURE=	yes
USE_GTEXINFO=	yes
CONFIGURE_ENV=	CPPFLAGS="-Dunix -I ${PREFIX}/include"

.include "../../mk/bsd.pkg.mk"
