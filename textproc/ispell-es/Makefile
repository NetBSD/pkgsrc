# $NetBSD: Makefile,v 1.2 2013/04/24 11:15:47 rodent Exp $
#

DISTNAME=	espa~nol-1.7
PKGNAME=	ispell-${DISTNAME:S/pa~nol//1}
CATEGORIES=	textproc
MASTER_SITES=	http://www.datsi.fi.upm.es/~coes/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://es.tldp.org/htmls/coes.html
COMMENT=	Spanish dictionary for interactive spelling checker

CONFLICTS+=	ispell-spanish-[0-9]*
DEPENDS+=	ispell>=3.1.20:../../textproc/ispell

MAKE_FLAGS+=	TMPDIR=${WRKDIR:Q}

INSTALLATION_DIRS=	lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/espa~nol.aff \
	    ${DESTDIR}${PREFIX}/lib/castellano.aff
	${INSTALL_DATA} ${WRKSRC}/espa~nol.hash \
	    ${DESTDIR}${PREFIX}/lib/castellano.hash

.include "../../mk/bsd.pkg.mk"
