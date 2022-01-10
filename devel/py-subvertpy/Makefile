# $NetBSD: Makefile,v 1.57 2022/01/10 22:17:11 wiz Exp $

DISTNAME=	subvertpy-0.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	18
CATEGORIES=	devel scm
MASTER_SITES=	http://samba.org/~jelmer/subvertpy/

MAINTAINER=	ddeus.pkgsrc@mailnull.com
HOMEPAGE=	https://launchpad.net/subvertpy
COMMENT=	Alternative Python bindings for Subversion
LICENSE=	gnu-lgpl-v2.1

MAKE_ENV+=	SVN_PREFIX=${BUILDLINK_PREFIX.subversion-base}

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.9.1

.include "../../devel/subversion-base/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
