# $NetBSD: Makefile,v 1.4 1998/06/22 12:44:30 agc Exp $
#

DISTNAME=	guavac-1.0
CATEGORIES=	lang
MASTER_SITES=	ftp://summit.stanford.edu/pub/guavac/ \
     ftp://ftp.Germany.EU.net/pub/programming/languages/java/guavac/ \
     ftp://sunsite.mff.cuni.cz/Languages/Java/guavac/ \
     ftp://sunsite.auc.dk/pub/languages/java/guavac/ \
     ftp://ftp.unicamp.br/pub/languages/java/guavac/

MAINTAINER=	packages@netbsd.org

GNU_CONFIGURE=  yes

post-install:
	${MV} ${PREFIX}/man/cat1/guavac.man ${PREFIX}/man/cat1/guavac.0

.include "../../mk/bsd.pkg.mk"
