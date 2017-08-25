# $NetBSD: Makefile,v 1.3 2017/08/25 17:03:25 jperkin Exp $

DISTNAME=	afero-0.0.20160605
PKGNAME=	go-${DISTNAME}
MASTER_SITES=	${MASTER_SITE_GITHUB:=spf13/}
CATEGORIES=	devel
GITHUB_TAG=	1a8ecf8b9da1fb5306e149e83128fc447957d2a8
GITHUB_PROJECT= ${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/spf13/afero
COMMENT=	FileSystem Abstraction System for Go
LICENSE=	apache-2.0

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/spf13/afero

.include "../../textproc/go-text/buildlink3.mk"
.include "../../security/go-sftp/buildlink3.mk"
.include "../../devel/go-fs/buildlink3.mk"
.include "../../devel/go-errors/buildlink3.mk"
.include "../../security/go-crypto/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
