# $NetBSD: Makefile,v 1.5 2003/04/02 08:46:25 salo Exp $
#

DISTNAME=	ispell-sk-0.2.0
PKGNAME=	${DISTNAME:S/sk/slovak/}
WRKSRC=		${WRKDIR}/${DISTNAME:S/-sk//}
CATEGORIES=	textproc
MASTER_SITES=	http://ispell.hq.sk/

MAINTAINER=	salo@netbsd.org
HOMEPAGE=	http://ispell.hq.sk/homepage/
COMMENT=	Slovak dictionary for ispell

DEPENDS+=	ispell-base>=3.1.20:../../textproc/ispell-base

MAKE_ENV+=	CAT=${CAT} SORT=${SORT}

.include "../../mk/bsd.pkg.mk"
