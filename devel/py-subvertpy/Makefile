# $NetBSD: Makefile,v 1.8 2011/11/24 21:52:25 cheusov Exp $

DISTNAME=	subvertpy-0.8.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel scm
MASTER_SITES=	http://launchpad.net/subvertpy/trunk/${PKGVERSION_NOREV}/+download/
MASTER_SITES+=	http://samba.org/~jelmer/subvertpy/

MAINTAINER=	ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://launchpad.net/subvertpy
COMMENT=	Alternative Python bindings for Subversion
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_ENV+=	SVN_PREFIX=${BUILDLINK_PREFIX.subversion-base}

.include "../../devel/subversion-base/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
