# $NetBSD: Makefile,v 1.3 2002/11/19 17:28:29 salo Exp $
#

DISTNAME=	ispell-sk-0.1.10
PKGNAME=	ispell-slovak-0.1.10
CATEGORIES=	textproc
MASTER_SITES=	http://ispell.hq.sk/

MAINTAINER=	salo@netbsd.org
HOMEPAGE=	http://ispell.hq.sk/homepage/
COMMENT=	Slovak dictionary for ispell

DEPENDS+=	ispell-base>=3.1.20:../../textproc/ispell-base

MAKE_ENV+=	CAT=${CAT} SORT=${SORT}

.include "../../mk/bsd.pkg.mk"
