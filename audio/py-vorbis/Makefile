# $NetBSD: Makefile,v 1.1.1.1 2004/02/15 15:47:29 minskim Exp $
#

DISTNAME=		pyvorbis-1.3
PKGNAME=                ${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=		audio
MASTER_SITES=		http://vorbis.com/files/1.0.1/unix/py/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://vorbis.com/
COMMENT=		Python bindings for Vorbis library

USE_BUILDLINK3=         yes
PY_PATCHPLIST=          yes
PYDISTUTILSPKG=         yes

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	${PYTHONBIN} config_unix.py
CONFIGURE_ARGS+=	--prefix ${PREFIX}

.include "../../audio/py-ogg/buildlink3.mk"
.include "../../audio/libogg/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
