# $NetBSD: Makefile,v 1.7 2023/08/14 05:24:08 wiz Exp $

DISTNAME=	git-filter-repo-2.38.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=newren/}
EXTRACT_SUFX=	.tar.xz
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/newren/git-filter-repo/
COMMENT=	Tool for rewriting git history
LICENSE=	mit

USE_LANGUAGES=	# none
USE_TOOLS+=	gmake
NO_BUILD=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27
REPLACE_PYTHON+=		git-filter-repo

INSTALLATION_DIRS+=	libexec/git-core ${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
