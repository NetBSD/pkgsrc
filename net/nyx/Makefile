# $NetBSD: Makefile,v 1.2 2019/04/25 07:33:12 maya Exp $

PKGREVISION= 1
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
