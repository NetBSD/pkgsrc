# $NetBSD: Makefile,v 1.6 2023/10/23 06:37:49 wiz Exp $

PKGREVISION= 5
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

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
