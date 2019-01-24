# $NetBSD: Makefile,v 1.8 2019/01/24 10:00:36 bsiegert Exp $

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
