# $NetBSD: Makefile,v 1.9 2000/01/15 18:46:29 jlam Exp $
#

DISTNAME=	pspp-0.3.0
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

DEPENDS+=	gettext-0.10.*:../../devel/gettext
DEPENDS+=	ncurses>=4.2:../../devel/ncurses

.if !exists(/usr/include/readline.h)
DEPENDS+=       readline-4.0:../../devel/readline
.endif

GNU_CONFIGURE=	yes
USE_GTEXINFO=	yes
CPPFLAGS+=	-Dunix=1 -I${LOCALBASE}/include
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
MAKE_ENV+=	pkgsysconfdir="${PREFIX}/etc/pspp"

.include "../../mk/bsd.pkg.mk"
