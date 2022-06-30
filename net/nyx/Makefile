# $NetBSD: Makefile,v 1.4 2022/06/30 11:18:43 nia Exp $

PKGREVISION= 3
.include "../../net/py-nyx/Makefile.common"

PKGNAME=	nyx-${VERSION}
CATEGORIES=	net
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nyx.torproject.org/
COMMENT=	Command-line monitor for the tor daemon
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses
DEPENDS+=	${PYPKGPREFIX}-nyx>=${VERSION}:../../net/py-nyx

META_PACKAGE=	yes

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
