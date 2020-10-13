# $NetBSD: Makefile,v 1.1 2020/10/13 02:33:10 maya Exp $

DISTNAME=	go-walker-0.1.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=saracen/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_TAG=	v0.1.1
GITHUB_PROJECT=	walker

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://godoc.org/github.com/saracen/walker
COMMENT=	faster, parallel version, of filepath.Walk
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG:S/^v//}
GO_SRCPATH=	github.com/saracen/walker

.include "../../lang/go/go-package.mk"
.include "../../devel/go-sync/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
