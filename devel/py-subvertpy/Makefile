# $NetBSD: Makefile,v 1.42 2017/11/30 16:45:22 adam Exp $

DISTNAME=	subvertpy-0.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel scm
MASTER_SITES=	http://samba.org/~jelmer/subvertpy/

MAINTAINER=	ddeus.pkgsrc@mailnull.com
HOMEPAGE=	https://launchpad.net/subvertpy
COMMENT=	Alternative Python bindings for Subversion
LICENSE=	gnu-lgpl-v2.1

MAKE_ENV+=	SVN_PREFIX=${BUILDLINK_PREFIX.subversion-base}

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 0.9.1

.include "../../devel/subversion-base/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
