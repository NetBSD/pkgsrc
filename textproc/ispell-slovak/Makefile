# $NetBSD: Makefile,v 1.1.1.1 2002/08/02 03:19:52 jschauma Exp $
#

DISTNAME=    ispell-sk-0.1.8.1
PKGNAME= ispell-slovak-0.1.8.1
CATEGORIES=  textproc
MASTER_SITES=    http://ispell.hq.sk/

MAINTAINER=  salo@Xtrmntr.org
HOMEPAGE=    http://ispell.hq.sk/homepage/
COMMENT= Slovak dictionary for ispell

DEPENDS+=    ispell-base>=3.1.20:../../textproc/ispell-base

MAKE_ENV+=   RM=${RM} CAT=${CAT} SORT=${SORT}

.include "../../mk/bsd.pkg.mk"
