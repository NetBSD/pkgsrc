# $NetBSD: Makefile,v 1.3 2009/05/16 15:20:51 epg Exp $

DISTNAME=	subvertpy-0.6.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
#PKGREVISION=	1
CATEGORIES=	devel scm
MASTER_SITES=	http://launchpad.net/subvertpy/trunk/0.6.6/+download/
MASTER_SITES+=	http://samba.org/~jelmer/subvertpy/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://launchpad.net/subvertpy
COMMENT=	Alternative Python bindings for Subversion

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_ENV+=	SVN_PREFIX=${BUILDLINK_PREFIX.subversion-base}
PYDISTUTILSPKG=	yes

.include "../../devel/subversion-base/buildlink3.mk"
.include "../../lang/python/extension.mk"
#.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
