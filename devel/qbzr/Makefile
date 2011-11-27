# $NetBSD: Makefile,v 1.13 2011/11/27 13:47:53 cheusov Exp $

DISTNAME=	qbzr-${VER}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/qbzr/0.21/${VER}/+download/
VER=		0.21.1

MAINTAINER=	ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://bazaar-vcs.org/QBzr
COMMENT=	GUI front end for Bazaar
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-qt4>=4.4:../../x11/py-qt4

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	msgfmt

WRKSRC=		${WRKDIR}/qbzr

PYDISTUTILSPKG=	yes
# Only this python versions are supported, see:
# http://doc.bazaar.canonical.com/bzr.dev/en/whats-new/whats-new-in-2.4.html
PYTHON_VERSIONS_ACCEPTED=	27 26

.include "../../devel/bzr/plugin.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
