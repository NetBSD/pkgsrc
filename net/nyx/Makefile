# $NetBSD: Makefile,v 1.5 2023/08/14 05:25:02 wiz Exp $

PKGREVISION= 4
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
