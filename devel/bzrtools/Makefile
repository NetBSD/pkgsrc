# $NetBSD: Makefile,v 1.15 2012/01/27 08:53:50 obache Exp $

DISTNAME=	bzrtools-${VER}
PKGREVISION=	1
CATEGORIES=	devel scm
MASTER_SITES=	http://launchpad.net/bzrtools/stable/${VER}/+download/
VER=		2.4.1

MAINTAINER=	ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://bazaar-vcs.org/BzrTools
COMMENT=	Collection of plugins for Bazaar
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
# Only this python versions are supported, see:
# http://doc.bazaar.canonical.com/bzr.dev/en/whats-new/whats-new-in-2.4.html
PYTHON_VERSIONS_ACCEPTED=	27 26

PYTHON_PATCH_SCRIPTS= check-release.py test.py

WRKSRC=		${WRKDIR}/bzrtools

USE_LANGUAGES=	#none

EGG_NAME=	BzrTools-${PKGVERSION_NOREV}

.include "../../devel/bzr/plugin.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
