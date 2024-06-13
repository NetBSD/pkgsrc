# $NetBSD: Makefile,v 1.46 2024/06/13 13:47:02 bsiegert Exp $

DISTNAME=		amazon-ecs-cli-1.21.0
PKGREVISION=		40
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=aws/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://docs.aws.amazon.com/AmazonECS/latest/developerguide/ECS_CLI.html
COMMENT=		Amazon ECS Cli
LICENSE=		apache-2.0

GO_BUILD_PATTERN=	${GO_SRCPATH}/ecs-cli
GO_DIST_BASE=		${DISTNAME}
GO_SRCPATH=		github.com/aws/amazon-ecs-cli

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/ecs-cli ${DESTDIR}${PREFIX}/bin

# XXX This doesn't build when being treated as a "module" by recent Go
# versions. On next update, check if this can be adjusted back to go-module.mk.
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
