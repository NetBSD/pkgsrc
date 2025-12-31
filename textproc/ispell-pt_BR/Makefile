# $NetBSD: Makefile,v 1.4 2025/12/31 09:00:32 wiz Exp $

DISTNAME=	br.ispell-2.4
PKGNAME=	ispell-br-2.4
CATEGORIES=	textproc
#MASTER_SITES=	http://www.ime.usp.br/~ueda/br.ispell/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.ime.usp.br/~ueda/br.ispell/summary.html
COMMENT=	Brazilian Portuguese dictionary for interactive spelling checker
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

BUILD_MAKE_FLAGS+=	AWK=${AWK}

DEPENDS+=	ispell-[0-9]*:../../textproc/ispell

.include "../../mk/bsd.pkg.mk"
