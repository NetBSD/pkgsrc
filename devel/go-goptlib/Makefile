# $NetBSD: Makefile,v 1.7.2.1 2019/02/08 12:03:10 spz Exp $

DISTNAME=	0.7
DIST_SUBDIR=	go-goptlib
PKGNAME=	${DIST_SUBDIR}-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel net
MASTER_SITES=	https://gitweb.torproject.org/pluggable-transports/goptlib.git/snapshot/

MAINTAINER=	alnsn@NetBSD.org
HOMEPAGE=	https://gitweb.torproject.org/pluggable-transports/goptlib.git
COMMENT=	Library for writing Tor pluggable transports in Go
LICENSE=	cc0-1.0-universal

WRKSRC=		${WRKDIR}
GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	git.torproject.org/pluggable-transports/goptlib.git

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
