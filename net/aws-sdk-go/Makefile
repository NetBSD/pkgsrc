# $NetBSD: Makefile,v 1.8 2018/03/13 17:14:28 bsiegert Exp $
#

DISTNAME=		aws-sdk-go-${GITHUB_TAG:S/v//}
PKGREVISION=		6
CATEGORIES=		net www
MASTER_SITES=		${MASTER_SITE_GITHUB:=aws/}
GITHUB_TAG=		v1.4.3

HOMEPAGE=		https://aws.amazon.com/sdk-for-go/
COMMENT=		Amazon AWS SDK for Go
LICENSE=		apache-2.0

GO_SRCPATH=		github.com/aws/aws-sdk-go
GO_DIST_BASE=		${DISTNAME}
GO_BUILD_PATTERN=	${GO_SRCPATH}/aws/... ${GO_SRCPATH}/service/...

post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/gopkg/pkg/${GO_PLATFORM}/${GO_SRCPATH}/private
	${RM} -rf ${DESTDIR}${PREFIX}/gopkg/pkg/${GO_PLATFORM}/${GO_SRCPATH}/vendor

.include "../../devel/go-testify/buildlink3.mk"  # for tests
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
