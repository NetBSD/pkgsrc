# $NetBSD: Makefile,v 1.6 2008/12/07 02:32:48 epg Exp $

DISTNAME=	bzr-svn-${VER}
#PKGREVISION=	1
CATEGORIES=	devel scm
MASTER_SITES=	http://launchpad.net/bzr-svn/0.4/${VER}/+download/
MASTER_SITES+=	http://samba.org/~jelmer/bzr/
VER=		0.4.16

MAINTAINER=	epg@NetBSD.org
HOMEPAGE=	http://bazaar-vcs.org/BzrForeignBranches/Subversion
COMMENT=	Foreign Subversion repositoriy support for Bazaar

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${SQLITE_DEP}
DEPENDS+=	bzr>=1.10{,nb[0-9]*}:../../devel/bzr

# for make test
USE_TOOLS+=	gmake

MAKE_ENV+=	SVN_PREFIX=${BUILDLINK_PREFIX.subversion-base}
PYDISTUTILSPKG=	yes
# NOTE: This must run in a UTF-8 locale, e.g. LC_TYPE=en_US.utf8 make test
TEST_TARGET=	check-verbose

.include "../../devel/bzr/plugin.mk"
.include "../../devel/subversion-base/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

.if ${PYVERSSUFFIX} == "2.5" || ${PYVERSSUFFIX} == "2.6"
SQLITE_DEP=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
.else
SQLITE_DEP=	${PYPKGPREFIX}-sqlite2>=2.3.5:../../databases/py-sqlite2
.endif
