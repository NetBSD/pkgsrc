# $NetBSD: Makefile,v 1.3 2004/10/03 00:13:09 tv Exp $
#

DISTNAME=		pymad-0.5.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=		audio python
MASTER_SITES=		http://spacepants.org/src/pymad/download/

MAINTAINER= 		froz@icix.org
HOMEPAGE=		http://spacepants.org/src/pymad
COMMENT=		Python bindings for libmad

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	${PYTHONBIN} config_unix.py
CONFIGURE_ARGS+=	--prefix ${PREFIX}

.include "../../audio/libmad/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
