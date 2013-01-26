# $NetBSD: Makefile,v 1.17 2013/01/26 21:37:24 adam Exp $

DISTNAME=	subvertpy-0.8.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel scm
MASTER_SITES=	http://launchpad.net/subvertpy/trunk/${PKGVERSION_NOREV}/+download/
MASTER_SITES+=	http://samba.org/~jelmer/subvertpy/

MAINTAINER=	ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://launchpad.net/subvertpy
COMMENT=	Alternative Python bindings for Subversion
LICENSE=	gnu-lgpl-v2.1

MAKE_ENV+=	SVN_PREFIX=${BUILDLINK_PREFIX.subversion-base}

PYTHON_SELF_CONFLICT=	yes

.include "../../devel/subversion-base/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
