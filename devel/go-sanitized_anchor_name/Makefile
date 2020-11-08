# $NetBSD: Makefile,v 1.29 2020/11/08 21:59:22 bsiegert Exp $

DISTNAME=	sanitized_anchor_name-0.0.20170919
PKGNAME=	go-${DISTNAME}
PKGREVISION=	22
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=shurcooL/}
GITHUB_TAG=	86672fcb3f950f35f2e675df2240550f2a50762f
GITHUB_PROJECT=	${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/shurcooL/sanitized_anchor_name
COMMENT=	Create sanitized anchor names
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/shurcooL/sanitized_anchor_name

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
