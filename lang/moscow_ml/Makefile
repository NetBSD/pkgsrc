# $NetBSD: Makefile,v 1.13 2001/02/17 09:07:20 agc Exp $

DISTNAME=       mos20src
PKGNAME=        moscow_ml-2.00
WRKSRC=		${WRKDIR}/mosml/src
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.dina.kvl.dk/pub/mosml/ \
		ftp://ftp.csd.uu.se/pub/mirror/mosml/

MAINTAINER=	lamj@stat.cmu.edu
HOMEPAGE=	http://www.dina.kvl.dk/~sestoft/mosml.html
COMMENT=	Moscow ML, a version of Standard ML

BUILD_DEPENDS+=	${PERL5}:../../lang/perl5-base

ALL_TARGET=	clean world

post-install:
	${MKDIR} ${PREFIX}/share/examples/moscow_ml
	${CP} -R ${WRKDIR}/mosml/examples/* ${PREFIX}/share/examples/moscow_ml
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/examples/moscow_ml
	${CHMOD} -R ugo+r ${PREFIX}/share/examples/moscow_ml

.include "../../mk/bsd.pkg.mk"
