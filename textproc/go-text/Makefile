# $NetBSD: Makefile,v 1.72.2.1 2023/10/22 18:44:19 spz Exp $

DISTNAME=		go-text-0.4.0
PKGREVISION=		10
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GITHUB:=golang/}
GITHUB_PROJECT=		text
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		bsiegert@NetBSD.org
HOMEPAGE=		https://golang.org/
COMMENT=		Supplementary text processing libraries for Go
LICENSE=		modified-bsd

GO_SRCPATH=		golang.org/x/text
GO_DIST_BASE=		${DISTNAME:S/go-//}

CHECK_RELRO_SKIP+=	bin/colcmp

pre-patch:
	${RM} -rf ${WRKSRC}/cmd/gotext ${WRKSRC}/message/pipeline

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
