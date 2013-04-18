# $NetBSD: Makefile,v 1.4 2013/04/18 07:39:18 wiz Exp $

DISTNAME=	reposurgeon-2.34
CATEGORIES=	devel scm
MASTER_SITES=	http://www.catb.org/~esr/reposurgeon/

MAINTAINER=	pkgsrc-users@NetBSD.or
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
