# New ports collection makefile for:    guavac
# Version required:     1.0
# Date created:         07-02-98
# Whom:                 mjl@emsi.priv.at
#
# $NetBSD: Makefile,v 1.1 1998/02/10 15:45:03 agc Exp $
#

CATEGORIES=	lang
DISTNAME=	guavac-1.0
MASTER_SITES=	ftp://summit.stanford.edu/pub/guavac/ \
     ftp://ftp.Germany.EU.net/pub/programming/languages/java/guavac/ \
     ftp://sunsite.mff.cuni.cz/Languages/Java/guavac/ \
     ftp://sunsite.auc.dk/pub/languages/java/guavac/ \
     ftp://ftp.unicamp.br/pub/languages/java/guavac/

GNU_CONFIGURE=  yes
MAN1=		guavac.1
CAT1=		guavac.0

post-install:
	${MV} ${PREFIX}/man/cat1/guavac.man ${PREFIX}/man/cat1/guavac.0

.include <bsd.port.mk>
