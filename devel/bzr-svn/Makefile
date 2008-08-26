# $NetBSD: Makefile,v 1.1.1.1 2008/08/26 01:44:50 epg Exp $

DISTNAME=	bzr-svn-${VER}
CATEGORIES=	devel scm
MASTER_SITES=	http://launchpad.net/bzr-svn/0.4/${VER}/+download/
MASTER_SITES=	http://samba.org/~jelmer/bzr/
VER=		0.4.11~rc1

MAINTAINER=	epg@NetBSD.org
HOMEPAGE=	http://bazaar-vcs.org/BzrForeignBranches/Subversion
COMMENT=	Foreign Subversion repositoriy support for Bazaar

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-sqlite2>=2.3.5:../../databases/py-sqlite2

# for make test
USE_TOOLS+=	gmake

MAKE_ENV+=	SVN_PREFIX=${BUILDLINK_PREFIX.subversion-base}
# no 2.4 support: https://bugs.launchpad.net/bzr-svn/+bug/256804
PYTHON_VERSIONS_ACCEPTED=25
PYDISTUTILSPKG=	yes
# NOTE: This must run in a UTF-8 locale, e.g. LC_TYPE=en_US.utf8 make test
TEST_TARGET=	check-verbose

.include "../../devel/bzr/plugin.mk"
.include "../../devel/subversion-base/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
