# $NetBSD: Makefile,v 1.20 2003/09/27 18:33:56 kristerw Exp $

DISTNAME=       mos20src
PKGNAME=        moscow_ml-2.00
PKGREVISION=	1
WRKSRC=		${WRKDIR}/mosml/src
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.dina.kvl.dk/pub/mosml/ \
		ftp://ftp.csd.uu.se/pub/mirror/mosml/

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://www.dina.kvl.dk/~sestoft/mosml.html
COMMENT=	Moscow ML, a version of Standard ML

USE_PERL5=	build

ALL_TARGET=	clean world

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/moscow_ml
	${CP} -R ${WRKDIR}/mosml/examples/* ${PREFIX}/share/examples/moscow_ml
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/examples/moscow_ml
	${CHMOD} -R ugo+r ${PREFIX}/share/examples/moscow_ml

.include "../../mk/bsd.pkg.mk"
