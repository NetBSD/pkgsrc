# $NetBSD: Makefile,v 1.7 2003/11/01 14:51:03 salo Exp $
#

DISTNAME=	ispell-sk-0.2.0
PKGNAME=	${DISTNAME:S/sk/slovak/}
CATEGORIES=	textproc
MASTER_SITES=	http://ispell.hq.sk/

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://ispell.hq.sk/homepage/
COMMENT=	Slovak dictionary for ispell

DEPENDS+=	ispell-base>=3.1.20:../../textproc/ispell-base

MAKE_ENV+=	CAT=${CAT} SORT=${SORT}

.include "../../mk/bsd.pkg.mk"
