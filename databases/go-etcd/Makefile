# $NetBSD: Makefile,v 1.17 2019/10/18 14:58:43 bsiegert Exp $

DISTNAME=	go-etcd-2.0.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=coreos/}
PKGREVISION=	13
CATEGORIES=	databases
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/coreos/go-etcd
COMMENT=	CoreOS etcd client for Go
LICENSE=	apache-2.0

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/coreos/go-etcd

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
