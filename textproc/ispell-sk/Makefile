# $NetBSD: Makefile,v 1.1 2013/04/24 02:20:42 rodent Exp $
#

DISTNAME=	ispell-sk-0.2.2
PKGNAME=	${DISTNAME:S/sk/slovak/}
CATEGORIES=	textproc
MASTER_SITES=	http://sk-spell.sk.cx/

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://sk-spell.sk.cx/?id=4
COMMENT=	Slovak dictionary for ispell

DEPENDS+=	ispell>=3.1.20:../../textproc/ispell

MAKE_ENV+=	CAT=${CAT:Q} SORT=${SORT:Q}

.include "../../mk/bsd.pkg.mk"
