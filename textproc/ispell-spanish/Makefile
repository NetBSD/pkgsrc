# $NetBSD: Makefile,v 1.6 2006/10/04 22:01:00 wiz Exp $
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

.include "../../mk/bsd.pkg.mk"
