# $NetBSD: Makefile,v 1.2 2013/04/24 11:15:46 rodent Exp $
#

DISTNAME=	ispell-sk-0.2.2
CATEGORIES=	textproc
MASTER_SITES=	http://sk-spell.sk.cx/

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://sk-spell.sk.cx/?id=4
COMMENT=	Slovak dictionary for ispell

CONFLICTS+=	ispell-slovak-[0-9]*
DEPENDS+=	ispell>=3.1.20:../../textproc/ispell

MAKE_ENV+=	CAT=${CAT:Q} SORT=${SORT:Q}

.include "../../mk/bsd.pkg.mk"
