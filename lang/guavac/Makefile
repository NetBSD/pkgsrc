# $NetBSD: Makefile,v 1.3 1998/04/15 10:38:28 agc Exp $
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
MAN1=		guavac.1
CAT1=		guavac.0

post-install:
	${MV} ${PREFIX}/man/cat1/guavac.man ${PREFIX}/man/cat1/guavac.0

.include "../../mk/bsd.pkg.mk"
