# $NetBSD: Makefile,v 1.10 2019/10/18 14:58:50 bsiegert Exp $

DISTNAME=	assert-0.0.0.20170929
PKGNAME=	go-${DISTNAME}
PKGREVISION=	9
MASTER_SITES=	${MASTER_SITE_GITHUB:=alecthomas/}
CATEGORIES=	devel
GITHUB_PROJECT=	assert
GITHUB_TAG=	405dbfeb8e38effee6e723317226e93fff912d06

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/alecthomas/assert
COMMENT=	Go assertion library
LICENSE=	mit

GO_DIST_BASE=	assert-${GITHUB_TAG}
GO_SRCPATH=	github.com/alecthomas/assert

.include "../../devel/go-colour/buildlink3.mk"
.include "../../devel/go-isatty/buildlink3.mk"
.include "../../devel/go-repr/buildlink3.mk"
.include "../../textproc/go-diff/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
