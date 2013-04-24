# $NetBSD: Makefile,v 1.1 2013/04/24 02:20:39 rodent Exp $
#

DISTNAME=	espa~nol-1.7
PKGNAME=	ispell-spanish-1.7
CATEGORIES=	textproc
MASTER_SITES=	http://www.datsi.fi.upm.es/~coes/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://es.tldp.org/htmls/coes.html
COMMENT=	Spanish dictionary for interactive spelling checker

DEPENDS+=	ispell>=3.1.20:../../textproc/ispell

MAKE_FLAGS+=	TMPDIR=${WRKDIR:Q}

INSTALLATION_DIRS=	lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/espa~nol.aff \
	    ${DESTDIR}${PREFIX}/lib/castellano.aff
	${INSTALL_DATA} ${WRKSRC}/espa~nol.hash \
	    ${DESTDIR}${PREFIX}/lib/castellano.hash

.include "../../mk/bsd.pkg.mk"
