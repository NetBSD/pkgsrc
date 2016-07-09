# $NetBSD: Makefile,v 1.19 2016/07/09 13:04:04 wiz Exp $

DISTNAME=	cryptkit-0.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cryptkit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/cryptkit/
COMMENT=	Python Cryptographic Toolkit

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # not yet ported as of 0.9

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
