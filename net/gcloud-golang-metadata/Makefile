# $NetBSD: Makefile,v 1.6 2016/02/23 20:18:11 bsiegert Exp $
#

DISTNAME=		gcloud-golang
PKGNAME=		gcloud-golang-metadata-20150310
PKGREVISION=		3
GITHUB_PROJECT=		${DISTNAME}
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=GoogleCloudPlatform/}
GITHUB_TAG=		9e1852f597

MAINTAINER=		bsiegert@NetBSD.org
HOMEPAGE=		http://golang.org/
COMMENT=		Google Compute Engine metadata package
LICENSE=		modified-bsd

GO_SRCPATH=		google.golang.org/cloud
GO_BUILD_PATTERN=	${GO_SRCPATH}/compute/metadata
GO_DIST_BASE=		${DISTNAME}-${GITHUB_TAG}*

# Remove all code except compute/metadata and internal
pre-patch:
	cd ${WRKSRC} && for i in *; do \
		case $$i in \
		c*|i*) ;; \
		*) ${RM} -fr $$i ;; \
		esac; \
		done
	${RM} -fr ${WRKSRC}/cloud*go
	${RM} -fr ${WRKSRC}/internal/datastore
	${RM} -fr ${WRKSRC}/internal/testutil

.include "../../net/go-net/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
