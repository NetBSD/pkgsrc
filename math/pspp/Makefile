# $NetBSD: Makefile,v 1.6 1999/07/13 01:31:06 jlam Exp $
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

BUILD_DEPENDS+=	autoconf:../../devel/autoconf
DEPENDS+=	gettext-0.10.35:../../devel/gettext
DEPENDS+=	ncurses-4.2:../../devel/ncurses

.if !exists(/usr/include/readline.h)
DEPENDS+=       readline-4.0:../../devel/readline
.endif

GNU_CONFIGURE=	yes
USE_GTEXINFO=	yes
CPPFLAGS+=	-Dunix=1 -I${LOCALBASE}/include
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

pre-configure:
	( cd ${WRKSRC}; autoconf )

.include "../../mk/bsd.pkg.mk"
