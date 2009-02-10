# $NetBSD: Makefile,v 1.10 2009/02/10 13:09:35 abs Exp $

DISTNAME=	msu-1.09
CATEGORIES=	security
MASTER_SITES=	http://msu.googlecode.com/files/
EXTRACT_SUFX=	.tbz

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://code.google.com/p/msu/
COMMENT=	Mini passwordless su

MAKE_ENV+=	SYSCONFDIR=${PKG_SYSCONFDIR:Q}

PKG_DESTDIR_SUPPORT=    destdir

.include "../../mk/bsd.pkg.mk"
