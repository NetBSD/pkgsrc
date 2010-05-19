# $NetBSD: Makefile,v 1.11 2010/05/19 21:00:02 drochner Exp $
#

DISTNAME=		pyao-0.82
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		audio python
MASTER_SITES=		http://ekyo.nerim.net/software/pyogg/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://vorbis.com/
COMMENT=		Python bindings for libao

PKG_DESTDIR_SUPPORT=	user-destdir

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

HAS_CONFIGURE=		yes
CONFIG_SHELL=		${PYTHONBIN}
CONFIGURE_SCRIPT=	config_unix.py
CONFIGURE_ARGS+=	--prefix ${PREFIX}

.include "../../audio/libao/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
