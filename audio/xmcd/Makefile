# $NetBSD: Makefile,v 1.21 2000/03/16 15:30:02 wiz Exp $
#

DISTNAME=	xmcd-2.6
CATEGORIES=	audio
MASTER_SITES=	http://metalab.unc.edu/tkan/download/xmcd/src/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://metalab.unc.edu/tkan/xmcd/

DEPENDS+=	ncurses>=4.2:../../devel/ncurses

USE_MOTIF=	yes
USE_IMAKE=	yes
IS_INTERACTIVE=	yes	# asks a lot of questions
MAKE_ENV+=	MACHINE_ARCH="${MACHINE_ARCH}" SHELL=/bin/sh

post-install:
.for FILE in cda cddbcmd wm2xmcd xmcd
	@${TEST} -n "${STRIPFLAG}" && \
	strip ${PREFIX}/lib/X11/xmcd/bin-${OPSYS}-${MACHINE_ARCH}/${FILE}
.endfor
	${MV} ${PREFIX}/man/cat1/cda.1 ${PREFIX}/man/man1/cda.1
	${MV} ${PREFIX}/man/cat1/cddbcmd.1 ${PREFIX}/man/man1/cddbcmd.1
	${MV} ${PREFIX}/man/cat1/dp2xmcd.1 ${PREFIX}/man/man1/dp2xmcd.1
	${MV} ${PREFIX}/man/cat1/wm2xmcd.1 ${PREFIX}/man/man1/wm2xmcd.1
	${MV} ${PREFIX}/man/cat1/xmcd.1 ${PREFIX}/man/man1/xmcd.1
	${PREFIX}/lib/X11/xmcd/config/config.sh

.include "../../mk/bsd.pkg.mk"
