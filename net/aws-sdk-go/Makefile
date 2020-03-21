# $NetBSD: Makefile,v 1.25 2020/03/21 16:57:05 bsiegert Exp $
#

DISTNAME=		aws-sdk-go-${GITHUB_TAG:S/v//}
PKGREVISION=		16
CATEGORIES=		net www
MASTER_SITES=		${MASTER_SITE_GITHUB:=aws/}
GITHUB_TAG=		v1.13.13

HOMEPAGE=		https://aws.amazon.com/sdk-for-go/
COMMENT=		Amazon AWS SDK for Go
LICENSE=		apache-2.0

GO_SRCPATH=		github.com/aws/aws-sdk-go
GO_DIST_BASE=		${DISTNAME}
GO_BUILD_PATTERN=	${GO_SRCPATH}/aws/... ${GO_SRCPATH}/service/...

post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/gopkg/pkg/${GO_PLATFORM}/${GO_SRCPATH}/private
	${RM} -rf ${DESTDIR}${PREFIX}/gopkg/pkg/${GO_PLATFORM}/${GO_SRCPATH}/vendor

.include "../../net/go-net/buildlink3.mk"
.include "../../devel/go-testify/buildlink3.mk"  # for tests
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
