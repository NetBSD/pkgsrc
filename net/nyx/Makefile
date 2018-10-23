# $NetBSD: Makefile,v 1.1 2018/10/23 01:42:34 riastradh Exp $

.include "../../net/py-nyx/Makefile.common"

PKGNAME=	nyx-${VERSION}
CATEGORIES=	net
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nyx.torproject.org/
COMMENT=	Command-line monitor for the tor daemon
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-nyx>=${VERSION}:../../net/py-nyx

META_PACKAGE=	yes

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
