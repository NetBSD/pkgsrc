# $NetBSD: Makefile,v 1.8 2018/11/04 18:37:54 bsiegert Exp $

DISTNAME=	matterircd-0.16.5
MASTER_SITES=	${MASTER_SITE_GITHUB:=42wim/}
PKGREVISION=	3
CATEGORIES=	chat
GITHUB_TAG=	v${PKGVERSION_NOREV}
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/42wim/matterircd
COMMENT=	Minimal IRC server which integrates with Mattermost and Slack
LICENSE=	mit

GO_DIST_BASE=	${PKGNAME_NOREV}
GO_SRCPATH=	github.com/42wim/matterircd
GO_BUILD_PATTERN=	${GO_SRCPATH}

pre-configure:
	${RM} -rf ${WRKSRC}/vendor/github.com/mattermost/platform/vendor/github.com/alecthomas/log4go/examples

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/matterircd ${DESTDIR}${PREFIX}/bin

.include "../../devel/go-golang-lru/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
