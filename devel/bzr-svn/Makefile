# $NetBSD: Makefile,v 1.16 2010/02/10 19:17:35 joerg Exp $

DISTNAME=	bzr-svn-${VER}
PKGREVISION=	1
CATEGORIES=	devel scm
MASTER_SITES=	http://launchpad.net/bzr-svn/1.0/${VER}/+download/
MASTER_SITES+=	http://samba.org/~jelmer/bzr/
VER=		1.0.0

MAINTAINER=	epg@NetBSD.org
HOMEPAGE=	http://bazaar-vcs.org/BzrForeignBranches/Subversion
COMMENT=	Foreign Subversion repository support for Bazaar
LICENSE=	gnu-gpl-v2

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
