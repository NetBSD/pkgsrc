# $NetBSD: Makefile,v 1.23 2022/01/10 08:49:05 wiz Exp $

DISTNAME=		pyao-0.82
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=		2
CATEGORIES=		audio python
MASTER_SITES=		http://ekyo.nerim.net/software/pyogg/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://vorbis.com/
COMMENT=		Python bindings for libao
LICENSE=		gnu-gpl-v2

HAS_CONFIGURE=		yes
CONFIG_SHELL=		${PYTHONBIN}
CONFIGURE_SCRIPT=	config_unix.py
CONFIGURE_ARGS+=	--prefix ${PREFIX}

CONFLICTS=		${PYPKGPREFIX}-pyao-[0-9]*

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.82

.include "../../audio/libao/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
