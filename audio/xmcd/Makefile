# $NetBSD: Makefile,v 1.10 1998/06/18 16:15:11 agc Exp $
# FreeBSD Id: Makefile,v 1.8 1997/09/08 13:20:10 tg Exp 
#

DISTNAME=	xmcd-2.3
CATEGORIES=	audio
MASTER_SITES=	http://mercury.hypersurf.com/~amb/download/xmcd/src/

MAINTAINER=	hubertf@netbsd.org

USE_MOTIF=	yes
USE_IMAKE=	yes
IS_INTERACTIVE=	yes	# asks a lot of questions

post-install:
	@strip ${PREFIX}/bin/xmcd
	@strip ${PREFIX}/bin/cda
	@strip ${PREFIX}/bin/cddbcmd
	@strip ${PREFIX}/bin/wm2xmcd
	${MV} ${PREFIX}/man/cat1/xmcd.1 ${PREFIX}/man/man1/xmcd.1
	${MV} ${PREFIX}/man/cat1/cda.1 ${PREFIX}/man/man1/cda.1
	${MV} ${PREFIX}/man/cat1/cddbcmd.1 ${PREFIX}/man/man1/cddbcmd.1
	${MV} ${PREFIX}/man/cat1/wm2xmcd.1 ${PREFIX}/man/man1/wm2xmcd.1

.include "../../mk/bsd.pkg.mk"
