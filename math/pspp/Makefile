# $NetBSD: Makefile,v 1.1.1.1 1998/10/26 18:54:42 frueauf Exp $
#

DISTNAME=	pspp-0.2.0
CATEGORIES=	math
MASTER_SITES=	ftp://franz.stat.wisc.edu/pub/PSPP/ \
		ftp://alpha.gnu.org/gnu/pspp/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/pspp/

DEPENDS+=	gettext-0.10:../../misc/gettext
DEPENDS+=	readline-2.2:../../devel/readline
DEPENDS+=	ncurses-1.9.9g:../../devel/ncurses

GNU_CONFIGURE=	yes
USE_GTEXINFO=	yes
CONFIGURE_ENV=	CPPFLAGS="-Dunix -I ${PREFIX}/include"

.include "../../mk/bsd.pkg.mk"
