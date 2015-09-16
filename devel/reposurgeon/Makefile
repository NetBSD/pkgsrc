# $NetBSD: Makefile,v 1.21 2015/09/16 16:13:16 wiz Exp $

DISTNAME=	reposurgeon-3.29
CATEGORIES=	devel scm
MASTER_SITES=	http://www.catb.org/~esr/reposurgeon/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/reposurgeon/
COMMENT=	Tool for editing version-control repository history
LICENSE=	modified-bsd

BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto
BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

USE_TOOLS+=	gmake
USE_LANGUAGES=	# none
MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	mandir=${PKGMANDIR}

REPLACE_PYTHON=	repodiffer reposurgeon
REPLACE_SH=	repotool

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # 3.26 uses commands module, which is deprecated in python-3.x

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
