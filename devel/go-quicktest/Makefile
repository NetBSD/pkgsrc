# $NetBSD: Makefile,v 1.1 2020/06/29 13:35:12 nikita Exp $

DISTNAME=		go-quicktest-1.10.0
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=frankban/}
GITHUB_PROJECT=		quicktest
GITHUB_TAG=		v1.10.0

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/frankban/quicktest
COMMENT=		Quick helpers for testing Go applications
LICENSE=		mit

GO_SRCPATH=		github.com/frankban/quicktest
GO_DIST_BASE=		${DISTNAME:S/go-//}


.include "../../devel/go-kr-pretty/buildlink3.mk"
.include "../../devel/go-cmp/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
