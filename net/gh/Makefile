# $NetBSD: Makefile,v 1.29 2021/11/05 20:02:44 bsiegert Exp $

DISTNAME=	gh-2.2.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=cli/}
GITHUB_PROJECT=	cli
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cli.github.com/
COMMENT=	GitHub CLI
LICENSE=	mit

DEPENDS+=		git-base-[0-9]*:../../devel/git-base

GO_BUILD_PATTERN=	./cmd/gh

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
