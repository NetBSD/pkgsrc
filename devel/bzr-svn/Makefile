# $NetBSD: Makefile,v 1.13 2009/07/02 05:26:46 epg Exp $

DISTNAME=	bzr-svn-${VER}
#PKGREVISION=	1
CATEGORIES=	devel scm
MASTER_SITES=	http://launchpad.net/bzr-svn/0.6/${VER}/+download/
MASTER_SITES+=	http://samba.org/~jelmer/bzr/
VER=		0.6.2

MAINTAINER=	epg@NetBSD.org
HOMEPAGE=	http://bazaar-vcs.org/BzrForeignBranches/Subversion
COMMENT=	Foreign Subversion repositoriy support for Bazaar

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${SQLITE_DEP}
DEPENDS+=	bzr>=1.11{,nb[0-9]*}:../../devel/bzr
DEPENDS+=	${PYPKGPREFIX}-subvertpy>=0.6.1:../../devel/py-subvertpy

# for make test
USE_TOOLS+=	gmake

PYDISTUTILSPKG=	yes
# NOTE: This must run in a UTF-8 locale, e.g. LC_TYPE=en_US.utf8 make test
TEST_TARGET=	check-verbose

.include "../../devel/bzr/plugin.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

.if ${PYVERSSUFFIX} == "2.5" || ${PYVERSSUFFIX} == "2.6"
SQLITE_DEP=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
.else
SQLITE_DEP=	${PYPKGPREFIX}-sqlite2>=2.3.5:../../databases/py-sqlite2
.endif
