# $NetBSD: Makefile,v 1.105.2.1 2025/04/05 20:45:12 maya Exp $

DISTNAME=	consul-1.2.3
PKGREVISION=	67
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.consul.io/
COMMENT=	Tool for service discovery, monitoring and configuration
LICENSE=	mpl-2.0

UNLIMIT_RESOURCES=	datasize virtualsize

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
