# $NetBSD: Makefile,v 1.22 2020/04/12 11:01:43 bsiegert Exp $

DISTNAME=	websocket-1.0.0
PKGNAME=	go-${DISTNAME}
PKGREVISION=	18
MASTER_SITES=	${MASTER_SITE_GITHUB:=gorilla/}
CATEGORIES=	net
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gorilla/websocket
COMMENT=	WebSocket implementation for Go
LICENSE=	2-clause-bsd

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/gorilla/websocket

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
