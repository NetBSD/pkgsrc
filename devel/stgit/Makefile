# $NetBSD: Makefile,v 1.3 2008/01/10 06:35:48 bjs Exp $

DISTNAME=	stgit-0.14.1
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
