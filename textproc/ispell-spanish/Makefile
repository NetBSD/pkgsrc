# $NetBSD: Makefile,v 1.3 2003/07/17 22:54:26 grant Exp $
#

DISTNAME=	espa~nol-1.7
PKGNAME=	ispell-spanish-1.7
CATEGORIES=	textproc
MASTER_SITES=	http://lucas.hispalinux.es/COES/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://lucas.hispalinux.es/htmls/coes.html
COMMENT=	Spanish dictionary for interactive spelling checker

DEPENDS+=	ispell-base>=3.1.20:../../textproc/ispell-base

MAKE_FLAGS+=	TMPDIR="${WRKDIR}"

.include "../../mk/bsd.pkg.mk"
