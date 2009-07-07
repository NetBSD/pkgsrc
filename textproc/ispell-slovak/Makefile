# $NetBSD: Makefile,v 1.13 2009/07/07 21:48:22 joerg Exp $
#

DISTNAME=	ispell-sk-0.2.2
PKGNAME=	${DISTNAME:S/sk/slovak/}
CATEGORIES=	textproc
MASTER_SITES=	http://sk-spell.sk.cx/

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://sk-spell.sk.cx/?id=4
COMMENT=	Slovak dictionary for ispell

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	ispell-base>=3.1.20:../../textproc/ispell-base

MAKE_ENV+=	CAT=${CAT:Q} SORT=${SORT:Q}

.include "../../mk/bsd.pkg.mk"
