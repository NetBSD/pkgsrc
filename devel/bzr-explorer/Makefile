# $NetBSD: Makefile,v 1.9 2012/04/22 08:45:49 cheusov Exp $

DISTNAME=	bzr-explorer-${VER}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/bzr-explorer/${VER:R}/${VER}/+download/
VER=		1.2.2

MAINTAINER=	ddeus.pkgsrc@mailnull.com
HOMEPAGE=	https://launchpad.net/bzr-explorer
COMMENT=	GUI frontend to bzr
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	msgfmt

DEPENDS+=	qbzr>=0.11:../../devel/qbzr
DEPENDS+=	${PYPKGPREFIX}-qt4>=4.4:../../x11/py-qt4

PYDISTUTILSPKG=	yes
# Only these python versions are supported, see:
# http://doc.bazaar.canonical.com/bzr.dev/en/whats-new/whats-new-in-2.4.html
PYTHON_VERSIONS_ACCEPTED=	27 26

.include "../../devel/bzr/plugin.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
