# $NetBSD: Makefile,v 1.6 2017/08/01 14:59:02 wiz Exp $
#

DISTNAME=		aws-sdk-go-${GITHUB_TAG:S/v//}
PKGREVISION=		4
CATEGORIES=		net www
MASTER_SITES=		${MASTER_SITE_GITHUB:=aws/}
GITHUB_TAG=		v1.4.3

HOMEPAGE=		https://aws.amazon.com/sdk-for-go/
COMMENT=		Amazon AWS SDK for Go
LICENSE=		apache-2.0

GO_SRCPATH=		github.com/aws/aws-sdk-go
GO_DIST_BASE=		${DISTNAME}
GO_BUILD_PATTERN=	${GO_SRCPATH}/aws/... ${GO_SRCPATH}/service/...

.include "../../devel/go-testify/buildlink3.mk"  # for tests
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
