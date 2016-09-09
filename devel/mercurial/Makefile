# $NetBSD: Makefile,v 1.104 2016/09/09 03:12:03 dholland Exp $

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
