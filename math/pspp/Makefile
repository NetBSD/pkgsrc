# $NetBSD: Makefile,v 1.5 1999/07/06 08:03:46 jlam Exp $
#

DISTNAME=	pspp-0.2.3
CATEGORIES=	math
MASTER_SITES=	ftp://franz.stat.wisc.edu/pub/PSPP/ \
		ftp://alpha.gnu.org/gnu/pspp/ \
		ftp://ftp.gwdg.de/pub/gnu-alpha/pspp/ \
		ftp://ftp.unex.es/pub/gnu-beta/pspp/ \
		ftp://ftp.cs.columbia.edu/.archives/gnu/alpha/pspp/ \
		ftp://ftp.kddlabs.co.jp/.1/alpha-gnu/pspp/ \
		ftp://ftp.icm.edu.pl/vol/rzm0/gnu-alpha/pspp/ \
		ftp://ftp.tuniv.szczecin.pl/mirrors/alpha.gnu.org/pub/gnu/pspp/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/pspp/

DEPENDS+=	gettext-0.10.35:../../devel/gettext
DEPENDS+=	readline-2.2:../../devel/readline
DEPENDS+=	ncurses-4.2:../../devel/ncurses

GNU_CONFIGURE=	yes
USE_GTEXINFO=	yes
CONFIGURE_ENV=	CPPFLAGS="-Dunix -I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
