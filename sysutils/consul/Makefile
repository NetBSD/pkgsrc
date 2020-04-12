# $NetBSD: Makefile,v 1.52 2020/04/12 11:01:46 bsiegert Exp $

DISTNAME=	consul-1.2.3
PKGREVISION=	15
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}

MAINTAINER=	fhajny@NetBSD.org
HOMEPAGE=	https://www.consul.io/
COMMENT=	Tool for service discovery, monitoring and configuration
LICENSE=	mpl-2.0

EXTRACT_USING=	bsdtar

GITHUB_TAG=	v${PKGVERSION_NOREV}

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/hashicorp/consul

USE_LANGUAGES=		c c99
USE_TOOLS+=		bash gmake

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/consul ${DESTDIR}${PREFIX}/bin

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
