# $NetBSD: Makefile,v 1.5 2005/12/05 20:51:03 rillig Exp $
#

DISTNAME=	espa~nol-1.7
PKGNAME=	ispell-spanish-1.7
CATEGORIES=	textproc
MASTER_SITES=	http://www.datsi.fi.upm.es/~coes/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://lucas.hispalinux.es/htmls/coes.html
COMMENT=	Spanish dictionary for interactive spelling checker

DEPENDS+=	ispell-base>=3.1.20:../../textproc/ispell-base

MAKE_FLAGS+=	TMPDIR=${WRKDIR:Q}

.include "../../mk/bsd.pkg.mk"
