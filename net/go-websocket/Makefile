# $NetBSD: Makefile,v 1.72 2024/08/11 15:57:04 bsiegert Exp $

DISTNAME=	websocket-1.4.2
PKGNAME=	go-${DISTNAME}
PKGREVISION=	38
MASTER_SITES=	${MASTER_SITE_GITHUB:=gorilla/}
CATEGORIES=	net
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gorilla/websocket
COMMENT=	Go implementation of the WebSocket protocol
LICENSE=	2-clause-bsd

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
