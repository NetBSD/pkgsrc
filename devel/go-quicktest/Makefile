# $NetBSD: Makefile,v 1.8 2020/11/13 19:26:12 bsiegert Exp $

DISTNAME=		go-quicktest-1.10.0
PKGREVISION=		6
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=frankban/}
GITHUB_PROJECT=		quicktest
GITHUB_TAG=		v${PKGVERSION_NOREV}

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
