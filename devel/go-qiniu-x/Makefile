# $NetBSD: Makefile,v 1.1 2023/04/22 15:49:13 nikita Exp $

DISTNAME=	qiniu-x-1.11.9
PKGNAME=	go-${DISTNAME}
MASTER_SITES=	${MASTER_SITE_GITHUB:=qiniu/}
CATEGORIES=	devel
GITHUB_PROJECT=	${PKGBASE:S/^go-qiniu-//}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/qiniu/x/
COMMENT=	Extension of Go standard library
LICENSE=	apache-2.0

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/qiniu/x

EXTRACT_USING=	bsdtar

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
