# $NetBSD: Makefile,v 1.8 2012/10/25 06:56:00 asau Exp $
#

DISTNAME=	espa~nol-1.7
PKGNAME=	ispell-spanish-1.7
CATEGORIES=	textproc
MASTER_SITES=	http://www.datsi.fi.upm.es/~coes/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://es.tldp.org/htmls/coes.html
COMMENT=	Spanish dictionary for interactive spelling checker

DEPENDS+=	ispell-base>=3.1.20:../../textproc/ispell-base

MAKE_FLAGS+=	TMPDIR=${WRKDIR:Q}

INSTALLATION_DIRS=	lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/espa~nol.aff \
	    ${DESTDIR}${PREFIX}/lib/castellano.aff
	${INSTALL_DATA} ${WRKSRC}/espa~nol.hash \
	    ${DESTDIR}${PREFIX}/lib/castellano.hash

.include "../../mk/bsd.pkg.mk"
