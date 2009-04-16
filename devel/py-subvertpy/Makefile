# $NetBSD: Makefile,v 1.2 2009/04/16 21:42:41 wiz Exp $

DISTNAME=	subvertpy-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel scm
MASTER_SITES=	http://launchpad.net/subvertpy/trunk/0.6.1/+download/

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
