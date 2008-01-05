# $NetBSD: Makefile,v 1.27 2008/01/05 09:22:06 tonio Exp $

DISTNAME=	mos20src
PKGNAME=	moscow_ml-2.00
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.dina.kvl.dk/pub/mosml/ \
		ftp://ftp.csd.uu.se/pub/mirror/mosml/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dina.kvl.dk/~sestoft/mosml.html
COMMENT=	Moscow ML, a version of Standard ML

WRKSRC=		${WRKDIR}/mosml/src
USE_TOOLS+=	perl

BUILD_TARGET=	clean world
MAKE_JOBS_SAFE=	no

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/moscow_ml
	${CP} -R ${WRKDIR}/mosml/examples/* ${PREFIX}/share/examples/moscow_ml
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/examples/moscow_ml
	${CHMOD} -R ugo+r ${PREFIX}/share/examples/moscow_ml

.include "../../mk/bsd.pkg.mk"
