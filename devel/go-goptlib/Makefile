# $NetBSD: Makefile,v 1.24 2020/07/17 18:04:17 bsiegert Exp $

DISTNAME=	1.0.0
DIST_SUBDIR=	go-goptlib
PKGNAME=	${DIST_SUBDIR}-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	devel net
MASTER_SITES=	https://gitweb.torproject.org/pluggable-transports/goptlib.git/snapshot/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitweb.torproject.org/pluggable-transports/goptlib.git
COMMENT=	Library for writing Tor pluggable transports in Go
LICENSE=	cc0-1.0-universal

WRKSRC=		${WRKDIR}
GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	git.torproject.org/pluggable-transports/goptlib.git

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
