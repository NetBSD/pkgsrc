# $NetBSD: Makefile,v 1.34 2023/08/14 05:24:15 wiz Exp $

DISTNAME=	reposurgeon-3.41
PKGREVISION=	4
CATEGORIES=	devel scm
MASTER_SITES=	http://www.catb.org/~esr/reposurgeon/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/reposurgeon/
COMMENT=	Tool for editing version-control repository history
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto
TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

PYTHON_VERSIONS_ACCEPTED=	27

USE_TOOLS+=	gmake
USE_LANGUAGES=	# none
MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	mandir=${PKGMANDIR}

REPLACE_PYTHON=	repocutter repodiffer repomapper reposurgeon
REPLACE_SH=	repotool

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
