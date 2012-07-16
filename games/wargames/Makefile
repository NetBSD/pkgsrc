# $NetBSD: Makefile,v 1.2 2012/07/16 20:47:03 abs Exp $

VERSION=	1.02
DISTNAME=	abs0-wargames-${VERSION}-0-g0e9f20e
PKGNAME=	wargames-${VERSION}
CATEGORIES=	games
MASTER_SITES=	https://github.com/abs0/wargames/tarball/${VERSION}/

MAINTAINER=	abs@absd.org
HOMEPAGE=	https://github.com/abs0/wargames/tarball/
COMMENT=	Simulated interaction with the W.O.P.R. computer from War Games
LICENSE=	2-clause-bsd

FETCH_USING=	curl

WRKSRC=	${WRKDIR}/${DISTNAME:C:[^-]*-0-g::}

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.pkg.mk"
