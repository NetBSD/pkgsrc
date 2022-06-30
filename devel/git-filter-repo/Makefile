# $NetBSD: Makefile,v 1.5 2022/06/30 11:18:14 nia Exp $

DISTNAME=	git-filter-repo-2.34.0
EXTRACT_SUFX=	.tar.xz
GITHUB_PROJECT=	git-filter-repo
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
GITHUB_TYPE=	release
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=newren/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/newren/git-filter-repo/
COMMENT=	Tool for rewriting git history
LICENSE=	mit

USE_LANGUAGES=	# none
USE_TOOLS+=	gmake
BUILD_TARGET=	build

PYTHON_VERSIONS_INCOMPATIBLE=	27
REPLACE_PYTHON+=		git-filter-repo

INSTALLATION_DIRS+=	libexec/git-core ${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
