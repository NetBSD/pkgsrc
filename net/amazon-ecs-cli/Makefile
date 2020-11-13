# $NetBSD: Makefile,v 1.4 2020/11/13 19:26:17 bsiegert Exp $

DISTNAME=		amazon-ecs-cli-1.20.0
PKGREVISION=		3
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

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
