# $NetBSD: Makefile,v 1.1 2017/08/17 02:02:27 gavan Exp $

DISTNAME=	go-etcd-2.0.0
PKGNAME=	${DISTNAME}
MASTER_SITES=	${MASTER_SITE_GITHUB:=coreos/}
CATEGORIES=	databases
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT= ${PKGBASE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/coreos/go-etcd
COMMENT=	etcd client for Go
LICENSE=	apache-2.0

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/coreos/go-etcd

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"

