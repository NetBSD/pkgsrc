# $NetBSD: Makefile,v 1.18 2011/07/22 14:17:37 obache Exp $

DISTNAME=	bzr-svn-${VER}
CATEGORIES=	devel scm
MASTER_SITES=	http://launchpad.net/bzr-svn/1.0/${VER}/+download/
MASTER_SITES+=	http://samba.org/~jelmer/bzr/
VER=		1.0.2

MAINTAINER=	jan.m.danielsson@gmail.com
HOMEPAGE=	http://bazaar-vcs.org/BzrForeignBranches/Subversion
COMMENT=	Foreign Subversion repository support for Bazaar
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	bzr>=2.0:../../devel/bzr
DEPENDS+=	${PYPKGPREFIX}-subvertpy>=0.6.1:../../devel/py-subvertpy

.include "../../lang/python/pyversion.mk"

.if ${PYVERSSUFFIX} == "2.4"
DEPENDS=	${PYPKGPREFIX}-sqlite2>=2.3.5:../../databases/py-sqlite2
.else
DEPENDS=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
.endif

# for make test
USE_TOOLS+=	gmake

# NOTE: This must run in a UTF-8 locale, e.g. LC_TYPE=en_US.utf8 make test
#TEST_DEPENDS+=	${PYPKGPREFIX}-testtools-[0-9]*:../../devel/py-testtools
#TEST_DEPENDS+=	${PYPKGPREFIX}-paramiko-[0-9]*:../../security/py-paramiko
#TEST_TARGET=	check-verbose

.include "../../devel/bzr/plugin.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
