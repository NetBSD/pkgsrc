# $NetBSD: Makefile,v 1.1.1.1 2002/07/22 11:31:46 agc Exp $
#

DISTNAME=	espa~nol-1.7
PKGNAME=	ispell-spanish-1.7
CATEGORIES=	textproc
MASTER_SITES=	http://lucas.hispalinux.es/COES/

MAINTAINER=	jmmv@hispabsd.org
HOMEPAGE=	http://lucas.hispalinux.es/htmls/coes.html
COMMENT=	Spanish dictionary for interactive spelling checker

DEPENDS+=	ispell-base>=3.1.20:../../textproc/ispell-base

MAKE_FLAGS+=	TMPDIR="${WRKDIR}"

.include "../../mk/bsd.pkg.mk"
