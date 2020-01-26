# $NetBSD: Makefile,v 1.24 2020/01/26 17:30:45 rillig Exp $

DISTNAME=		pymad-0.6
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=		1
CATEGORIES=		audio python
MASTER_SITES=		http://spacepants.org/src/pymad/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://spacepants.org/src/pymad/
COMMENT=		Python bindings for libmad
LICENSE=		gnu-gpl-v2

HAS_CONFIGURE=		yes
CONFIG_SHELL=		${PYTHONBIN}
CONFIGURE_SCRIPT=	config_unix.py
CONFIGURE_ARGS+=	--prefix ${PREFIX}

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.6

.include "../../audio/libmad/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
