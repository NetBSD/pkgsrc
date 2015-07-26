# $NetBSD: Makefile,v 1.1.2.1 2015/07/26 19:53:23 tron Exp $
#

DISTNAME=		gcloud-golang
PKGNAME=		gcloud-golang-metadata-20150310
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
	for i in ${WRKSRC}/*; do \
		case $$i in \
		c*|i*) ;; \
		default) ${RM} -fr $$i ;; \
		esac; \
		done
	${RM} -fr ${WRKSRC}/cloud*go
	${RM} -fr ${WRKSRC}/internal/datastore
	${RM} -fr ${WRKSRC}/internal/testutil

.include "../../net/go-net/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
