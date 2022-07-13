# $NetBSD: Makefile,v 1.43 2022/07/13 16:02:57 bsiegert Exp $

# Please also update GH_REL_DATE when upgrading to a new release.

DISTNAME=	gh-2.12.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=cli/}
GITHUB_PROJECT=	cli
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cli.github.com/
COMMENT=	GitHub CLI
LICENSE=	mit

DEPENDS+=		git-base-[0-9]*:../../devel/git-base

GO_BUILD_PATTERN=	./cmd/gh

GH_REL_DATE=	2022-06-09

# Because we are not calling scripts/build as the Makefile for gh would
# do, we do not get these flags set. These flags make the output from
# "gh --version" meaningful.

GH_LDFLAGS=	-X github.com/cli/cli/v2/internal/build.Date=${GH_REL_DATE}
GH_LDFLAGS+=	-X github.com/cli/cli/v2/internal/build.Version=${PKGVERSION_NOREV}

do-build:
	${RUN} cd ${WRKSRC} && ${_ULIMIT_CMD} ${PKGSRC_SETENV} ${MAKE_ENV} \
		${GO} install -v -ldflags "${GH_LDFLAGS}" ${GO_BUILD_PATTERN}

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
