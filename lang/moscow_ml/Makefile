# $NetBSD: Makefile,v 1.5 1998/12/04 11:09:46 frueauf Exp $
#

DISTNAME=       mos14src
PKGNAME=        moscow_ml-1.43
WRKSRC=		${WRKDIR}/mosml/src
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.dina.kvl.dk/pub/mosml/ \
		ftp://ftp.csd.uu.se/pub/mirror/mosml/

MAINTAINER=	lamj@stat.cmu.edu
HOMEPAGE=	http://www.dina.kvl.dk/~sestoft/mosml.html

BUILD_DEPENDS+=	perl-5.00404:../../lang/perl5

CONFLICTS=	moscow_ml-1.42

ALL_TARGET=	clean world

post-install:
	${TOUCH} ${WRKDIR}/mosml/examples/helpsigs/htmlsigs/.keep_me
	${MKDIR} ${PREFIX}/share/doc/moscow_ml
	${MKDIR} ${PREFIX}/share/examples/moscow_ml
	${CP} ${WRKDIR}/mosml/copyrght/* ${PREFIX}/share/doc/moscow_ml
	${CP} -R ${WRKDIR}/mosml/doc/* ${PREFIX}/share/doc/moscow_ml
	${CP} -R ${WRKDIR}/mosml/examples/* ${PREFIX}/share/examples/moscow_ml
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/moscow_ml
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/examples/moscow_ml
	${CHMOD} -R ugo+r ${PREFIX}/share/doc/moscow_ml
	${CHMOD} -R ugo+r ${PREFIX}/share/examples/moscow_ml

.include "../../mk/bsd.pkg.mk"
