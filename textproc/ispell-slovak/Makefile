# $NetBSD: Makefile,v 1.2 2002/08/10 16:02:49 jschauma Exp $
#

DISTNAME=	ispell-sk-0.1.9.1
PKGNAME=	ispell-slovak-0.1.9.1
CATEGORIES=	textproc
MASTER_SITES=    http://ispell.hq.sk/

MAINTAINER=	salo@Xtrmntr.org
HOMEPAGE=	http://ispell.hq.sk/homepage/
COMMENT=	Slovak dictionary for ispell

DEPENDS+=	ispell-base>=3.1.20:../../textproc/ispell-base

MAKE_ENV+=	CAT=${CAT} SORT=${SORT}

.include "../../mk/bsd.pkg.mk"
