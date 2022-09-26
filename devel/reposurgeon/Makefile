# $NetBSD: Makefile,v 1.32 2022/09/26 16:22:10 ryoon Exp $

DISTNAME=	reposurgeon-3.41
PKGREVISION=	3
CATEGORIES=	devel scm
MASTER_SITES=	http://www.catb.org/~esr/reposurgeon/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/reposurgeon/
COMMENT=	Tool for editing version-control repository history
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto
BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

PYTHON_VERSIONS_ACCEPTED=	27

USE_TOOLS+=	gmake
USE_LANGUAGES=	# none
MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	mandir=${PKGMANDIR}

REPLACE_PYTHON=	repocutter repodiffer repomapper reposurgeon
REPLACE_SH=	repotool

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
