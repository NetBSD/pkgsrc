# $NetBSD: Makefile,v 1.12 2020/01/10 13:32:17 bsiegert Exp $

DISTNAME=	go-diff-1.0.0
PKGNAME=	go-${DISTNAME}
PKGREVISION=	11
MASTER_SITES=	${MASTER_SITE_GITHUB:=sergi/}
CATEGORIES=	textproc
GITHUB_PROJECT=	go-diff
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sergi/go-diff
COMMENT=	Diff, match and patch text in Go
LICENSE=	apache-2.0

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/sergi/go-diff

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
