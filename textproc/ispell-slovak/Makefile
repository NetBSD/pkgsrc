# $NetBSD: Makefile,v 1.8 2003/12/03 09:32:12 salo Exp $
#

DISTNAME=	ispell-sk-0.2.1
PKGNAME=	${DISTNAME:S/sk/slovak/}
CATEGORIES=	textproc
MASTER_SITES=	http://spell.linux.sk/ispell/

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://spell.linux.sk/ispell/
COMMENT=	Slovak dictionary for ispell

DEPENDS+=	ispell-base>=3.1.20:../../textproc/ispell-base

MAKE_ENV+=	CAT=${CAT} SORT=${SORT}

.include "../../mk/bsd.pkg.mk"
