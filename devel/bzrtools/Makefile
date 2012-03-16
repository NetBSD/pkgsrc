# $NetBSD: Makefile,v 1.17 2012/03/16 21:04:40 cheusov Exp $

PKGNAME=	bzrtools-${VER}
DISTNAME=	bzrtools-${VER:R}
CATEGORIES=	devel scm
MASTER_SITES=	http://launchpad.net/bzrtools/stable/${VER:R}/+download/
VER=		2.5.0

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
