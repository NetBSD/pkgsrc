# $NetBSD: Makefile,v 1.9 2007/03/17 20:43:23 rillig Exp $
#

DISTNAME=		pymad-0.5.4
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=		audio python
MASTER_SITES=		http://spacepants.org/src/pymad/download/

MAINTAINER=	froz@icix.org
HOMEPAGE=		http://spacepants.org/src/pymad/
COMMENT=		Python bindings for libmad

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

HAS_CONFIGURE=		yes
CONFIG_SHELL=		${PYTHONBIN}
CONFIGURE_SCRIPT=	config_unix.py
CONFIGURE_ARGS+=	--prefix ${PREFIX}

.include "../../audio/libmad/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
