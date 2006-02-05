# $NetBSD: Makefile,v 1.7 2006/02/05 23:08:13 joerg Exp $
#

DISTNAME=		pyao-0.81
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		audio python
MASTER_SITES=		http://vorbis.com/files/1.0.1/unix/py/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://vorbis.com/
COMMENT=		Python bindings for libao

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	${PYTHONBIN} config_unix.py
CONFIGURE_ARGS+=	--prefix ${PREFIX}

.include "../../audio/libao/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
