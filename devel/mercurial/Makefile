# $NetBSD: Makefile,v 1.105 2019/04/25 07:32:48 maya Exp $

PKGREVISION= 1
.include "../../devel/py-mercurial/Makefile.version"

PKGNAME=	mercurial-${VERSION}
CATEGORIES=	devel scm
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	https://www.mercurial-scm.org/
COMMENT=	Fast, lightweight source control management system (meta package)
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 # OR newer

DEPENDS+=	${PYPKGPREFIX}-mercurial>=${VERSION}:../../devel/py-mercurial

META_PACKAGE=	yes

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
