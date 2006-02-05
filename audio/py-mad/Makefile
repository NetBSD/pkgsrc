# $NetBSD: Makefile,v 1.5 2006/02/05 23:08:13 joerg Exp $
#

DISTNAME=		pymad-0.5.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	2
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
