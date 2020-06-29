# $NetBSD: Makefile,v 1.1 2020/06/29 13:22:14 nikita Exp $

DISTNAME=		go-kr-pretty-0.2.0
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=kr/}
GITHUB_PROJECT=		pretty
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/kr/pretty
COMMENT=		Go package for pretty-printing Go values
LICENSE=		mit

GO_SRCPATH=		github.com/kr/pretty
GO_DIST_BASE=		${DISTNAME:S/go-kr-//}


.include "../../textproc/go-kr-text/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
