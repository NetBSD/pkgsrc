# $NetBSD: Makefile,v 1.16 2001/04/30 04:16:10 jlam Exp $

DISTNAME=       mos20src
PKGNAME=        moscow_ml-2.00
WRKSRC=		${WRKDIR}/mosml/src
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.dina.kvl.dk/pub/mosml/ \
		ftp://ftp.csd.uu.se/pub/mirror/mosml/

MAINTAINER=	lamj@stat.cmu.edu
HOMEPAGE=	http://www.dina.kvl.dk/~sestoft/mosml.html
COMMENT=	Moscow ML, a version of Standard ML

BUILD_DEPENDS+=	perl>=${PERL5_REQD}:../../lang/perl5

ALL_TARGET=	clean world

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/moscow_ml
	${CP} -R ${WRKDIR}/mosml/examples/* ${PREFIX}/share/examples/moscow_ml
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/examples/moscow_ml
	${CHMOD} -R ugo+r ${PREFIX}/share/examples/moscow_ml

.include "../../mk/bsd.pkg.mk"
