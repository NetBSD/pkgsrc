# $NetBSD: Makefile,v 1.6 2006/07/24 20:25:31 drochner Exp $
#

DISTNAME=		pymad-0.5.4
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=		audio python
MASTER_SITES=		http://spacepants.org/src/pymad/download/

MAINTAINER= 		froz@icix.org
HOMEPAGE=		http://spacepants.org/src/pymad
COMMENT=		Python bindings for libmad

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	${PYTHONBIN} config_unix.py
CONFIGURE_ARGS+=	--prefix ${PREFIX}

.include "../../audio/libmad/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
