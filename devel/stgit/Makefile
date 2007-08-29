# $NetBSD: Makefile,v 1.2 2007/08/29 23:07:48 wiz Exp $

DISTNAME=	stgit-0.13
CATEGORIES=	devel
MASTER_SITES=	http://homepage.ntlworld.com/cmarinas/stgit/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.procode.org/stgit/
COMMENT=	Stacked GIT

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED?=	24 23
PYTHON_PATCH_SCRIPTS=		*.py stgit/*.py
PYDISTUTILSPKG=			yes
PYSETUPINSTALLARGS=		--prefix=${PREFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
