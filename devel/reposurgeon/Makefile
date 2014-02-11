# $NetBSD: Makefile,v 1.13 2014/02/11 20:53:25 agc Exp $

DISTNAME=	reposurgeon-3.2
CATEGORIES=	devel scm
MASTER_SITES=	http://www.catb.org/~esr/reposurgeon/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/reposurgeon/
COMMENT=	Tool for editing version-control repository history
LICENSE=	modified-bsd

BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto
BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

USE_LANGUAGES=	# none
MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	mandir=${PKGMANDIR}

REPLACE_PYTHON=	repodiffer reposurgeon
REPLACE_SH=	repopuller

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
