# $NetBSD: Makefile,v 1.2 2019/04/25 07:33:12 maya Exp $

PKGREVISION= 1
.include "../../net/py-onionbalance/Makefile.common"

PKGNAME=	onionbalance-${VERSION}
CATEGORIES=	net
MASTER_FILES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://onionbalance.readthedocs.org/
COMMENT=	Tor onion service load balancer
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-onionbalance>=${VERSION}:../../net/py-onionbalance

META_PACKAGE=	yes

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
