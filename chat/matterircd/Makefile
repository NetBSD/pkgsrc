# $NetBSD: Makefile,v 1.72 2024/06/01 14:02:48 bsiegert Exp $

DISTNAME=	matterircd-0.28.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=42wim/}
PKGREVISION=	5
CATEGORIES=	chat
GITHUB_TAG=	v${PKGVERSION_NOREV}
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/42wim/matterircd
COMMENT=	Minimal IRC server which integrates with Mattermost and Slack
LICENSE=	mit

GO_BUILD_PATTERN=	.

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/matterircd ${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
