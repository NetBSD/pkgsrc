# $NetBSD: Makefile,v 1.102 2014/04/21 13:35:44 wiz Exp $

.include "../../devel/py-mercurial/Makefile.version"

PKGNAME=	mercurial-${VERSION}
PKGREVISION=	1
CATEGORIES=	devel scm
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://mercurial.selenic.com/
COMMENT=	Fast, lightweight source control management system (meta package)
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 # OR newer

DEPENDS+=	${PYPKGPREFIX}-mercurial>=${VERSION}:../../devel/py-mercurial

META_PACKAGE=	yes

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
