# $NetBSD: Makefile,v 1.5 1998/08/20 15:17:04 tsarna Exp $
#

DISTNAME=	guavac-1.0
CATEGORIES=	lang
MASTER_SITES=	ftp://summit.stanford.edu/pub/guavac/ \
     ftp://ftp.Germany.EU.net/pub/programming/languages/java/guavac/ \
     ftp://sunsite.mff.cuni.cz/Languages/Java/guavac/ \
     ftp://sunsite.auc.dk/pub/languages/java/guavac/ \
     ftp://ftp.unicamp.br/pub/languages/java/guavac/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cs.berkeley.edu/~engberg/guavac

GNU_CONFIGURE=  yes

post-install:
	${MV} ${PREFIX}/man/cat1/guavac.man ${PREFIX}/man/cat1/guavac.0

.include "../../mk/bsd.pkg.mk"
