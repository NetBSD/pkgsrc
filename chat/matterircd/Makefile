# $NetBSD: Makefile,v 1.1 2017/09/08 16:16:58 jperkin Exp $

DISTNAME=	matterircd-0.14.0
MASTER_SITES=	${MASTER_SITE_GITHUB:=42wim/}
CATEGORIES=	chat
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/42wim/matterircd
COMMENT=	Minimal IRC server which integrates with Mattermost and Slack
LICENSE=	mit

GO_DIST_BASE=	${PKGNAME_NOREV}
GO_SRCPATH=	github.com/42wim/matterircd
GO_BUILD_PATTERN=	${GO_SRCPATH}

pre-configure:
	${RM} -rf ${WRKSRC}/vendor/github.com/mattermost/platform/vendor/github.com/alecthomas/log4go/examples

.include "../../devel/go-golang-lru/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
