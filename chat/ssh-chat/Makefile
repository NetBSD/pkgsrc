# $NetBSD: Makefile,v 1.36 2026/08/22 15:18:56 bsiegert Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	ssh-chat-1.10
PKGREVISION=	34
CATEGORIES=	chat security
MASTER_SITES=	${MASTER_SITE_GITHUB:=shazow/}
GITHUB_PROJECT=	ssh-chat

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/shazow/ssh-chat
COMMENT=	Chat over SSH
LICENSE=	mit

REPLACE_BASH+=	build_release

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
