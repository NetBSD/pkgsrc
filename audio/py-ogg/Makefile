# $NetBSD: Makefile,v 1.14 2014/05/09 07:36:54 wiz Exp $

DISTNAME=		pyogg-1.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=		3
CATEGORIES=		audio python
MASTER_SITES=		http://vorbis.com/files/1.0.1/unix/py/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://vorbis.com/
COMMENT=		Python bindings for OGG library
LICENSE=		gnu-lgpl-v2

HAS_CONFIGURE=		yes
CONFIG_SHELL=		${PYTHONBIN}
CONFIGURE_SCRIPT=	config_unix.py
CONFIGURE_ARGS+=	--prefix ${PREFIX}

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 1.3

.include "../../lang/python/distutils.mk"
.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
