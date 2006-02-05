# $NetBSD: Makefile,v 1.7 2006/02/05 23:08:13 joerg Exp $
#

DISTNAME=		pyvorbis-1.3
PKGNAME=                ${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	2
CATEGORIES=		audio python
MASTER_SITES=		http://vorbis.com/files/1.0.1/unix/py/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://vorbis.com/
COMMENT=		Python bindings for Vorbis library

PY_PATCHPLIST=          yes
PYDISTUTILSPKG=         yes

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	${PYTHONBIN} config_unix.py
CONFIGURE_ARGS+=	--prefix ${PREFIX}

.include "../../audio/py-ogg/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
