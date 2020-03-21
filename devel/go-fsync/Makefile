# $NetBSD: Makefile,v 1.21 2020/03/21 16:57:17 bsiegert Exp $

DISTNAME=	fsync-0.0.20170320
PKGNAME=	go-${DISTNAME}
PKGREVISION=	17
MASTER_SITES=	${MASTER_SITE_GITHUB:=spf13/}
CATEGORIES=	devel
GITHUB_TAG=	12a01e648f05a938100a26858d2d59a120307a18
GITHUB_PROJECT=	${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/spf13/fsync
COMMENT=	Package fsync keeps files and directories in sync
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/spf13/fsync

.include "../../devel/go-afero/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
