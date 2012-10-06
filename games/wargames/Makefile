# $NetBSD: Makefile,v 1.3 2012/10/06 11:54:58 asau Exp $

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

.include "../../mk/bsd.pkg.mk"
