# $NetBSD: Makefile,v 1.12 1998/11/05 06:26:08 mycroft Exp $
# FreeBSD Id: Makefile,v 1.8 1997/09/08 13:20:10 tg Exp 
#

DISTNAME=	xmcd-2.4
CATEGORIES=	audio
MASTER_SITES=	http://mercury.hypersurf.com/~amb/download/xmcd/src/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://sunsite.unc.edu/~cddb/xmcd/index.html

DEPENDS+=	ncurses-1.9.9g:../../devel/ncurses

CONFLICTS=	xmcd-2.3

USE_MOTIF=	yes
USE_IMAKE=	yes
IS_INTERACTIVE=	yes	# asks a lot of questions

post-install:
	@strip ${PREFIX}/bin/cda
	@strip ${PREFIX}/bin/cddbcmd
	@strip ${PREFIX}/bin/wm2xmcd
	@strip ${PREFIX}/bin/xmcd
	${MV} ${PREFIX}/man/cat1/cda.1 ${PREFIX}/man/man1/cda.1
	${MV} ${PREFIX}/man/cat1/cddbcmd.1 ${PREFIX}/man/man1/cddbcmd.1
	${MV} ${PREFIX}/man/cat1/dp2xmcd.1 ${PREFIX}/man/man1/dp2xmcd.1
	${MV} ${PREFIX}/man/cat1/wm2xmcd.1 ${PREFIX}/man/man1/wm2xmcd.1
	${MV} ${PREFIX}/man/cat1/xmcd.1 ${PREFIX}/man/man1/xmcd.1
	${PREFIX}/lib/X11/xmcd/config/config.sh

.include "../../mk/bsd.pkg.mk"
