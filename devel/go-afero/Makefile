# $NetBSD: Makefile,v 1.22 2020/03/21 16:57:15 bsiegert Exp $

DISTNAME=	afero-1.1.1
PKGNAME=	go-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=spf13/}
GITHUB_PROJECT=	${PKGBASE:S/^go-//}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/spf13/afero
COMMENT=	FileSystem Abstraction System for Go
LICENSE=	apache-2.0

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/spf13/afero

.include "../../textproc/go-text/buildlink3.mk"
.include "../../security/go-sftp/buildlink3.mk"
.include "../../devel/go-fs/buildlink3.mk"
.include "../../devel/go-errors/buildlink3.mk"
.include "../../security/go-crypto/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
