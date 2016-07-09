# $NetBSD: Makefile,v 1.32 2016/07/09 13:03:37 wiz Exp $

DISTNAME=	bzr-svn-${VER}
CATEGORIES=	devel scm
MASTER_SITES=	http://launchpad.net/bzr-svn/${VER:R}/${VER}/+download/
MASTER_SITES+=	http://samba.org/~jelmer/bzr/
VER=		1.2.1

MAINTAINER=	ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://bazaar-vcs.org/BzrForeignBranches/Subversion
COMMENT=	Foreign Subversion repository support for Bazaar
LICENSE=	gnu-gpl-v2

REPLACE_PYTHON= info.py wiki.py

DEPENDS+=	${PYPKGPREFIX}-subvertpy>=0.8.8:../../devel/py-subvertpy
DEPENDS=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

# for make test
USE_TOOLS+=	gmake
USE_LANGUAGES=	#none

# NOTE: This must run in a UTF-8 locale, e.g. LC_TYPE=en_US.utf8 make test
#TEST_DEPENDS+=	${PYPKGPREFIX}-testtools-[0-9]*:../../devel/py-testtools
#TEST_DEPENDS+=	${PYPKGPREFIX}-paramiko-[0-9]*:../../security/py-paramiko
#TEST_TARGET=	check-verbose

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-subvertpy

.include "../../devel/bzr/plugin.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
