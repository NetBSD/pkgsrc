# $NetBSD: Makefile,v 1.12 2019/11/04 21:12:55 rillig Exp $

DISTNAME=	msu-1.09
CATEGORIES=	security
MASTER_SITES=	http://msu.googlecode.com/files/
EXTRACT_SUFX=	.tbz

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	https://code.google.com/archive/p/msu/
COMMENT=	Mini passwordless su

MAKE_ENV+=	SYSCONFDIR=${PKG_SYSCONFDIR:Q}

PKG_DESTDIR_SUPPORT=	destdir

.include "../../mk/bsd.pkg.mk"
