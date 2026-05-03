# $NetBSD: Makefile,v 1.1 2026/05/03 20:34:45 kim Exp $

.include "../../misc/py-tmuxp/version.mk"

PKGNAME=	tmuxp-${VERSION}
CATEGORIES=	misc python
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tmuxp.git-pull.com/
COMMENT=	Session manager for tmux (meta package)
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-tmuxp>=${VERSION}:../../misc/py-tmuxp

META_PACKAGE=	yes

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
