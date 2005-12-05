# $NetBSD: Makefile,v 1.10 2005/12/05 20:51:03 rillig Exp $
#

DISTNAME=	ispell-sk-0.2.2
PKGNAME=	${DISTNAME:S/sk/slovak/}
CATEGORIES=	textproc
MASTER_SITES=	http://spell.linux.sk/

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://spell.linux.sk/ispell.html
COMMENT=	Slovak dictionary for ispell

DEPENDS+=	ispell-base>=3.1.20:../../textproc/ispell-base

MAKE_ENV+=	CAT=${CAT:Q} SORT=${SORT:Q}

.include "../../mk/bsd.pkg.mk"
