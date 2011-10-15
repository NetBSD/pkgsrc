# $NetBSD: Makefile,v 1.13 2011/10/15 10:18:06 obache Exp $
#

DISTNAME=		pymad-0.6
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=		1
CATEGORIES=		audio python
MASTER_SITES=		http://spacepants.org/src/pymad/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://spacepants.org/src/pymad/
COMMENT=		Python bindings for libmad
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=		yes
CONFIG_SHELL=		${PYTHONBIN}
CONFIGURE_SCRIPT=	config_unix.py
CONFIGURE_ARGS+=	--prefix ${PREFIX}

.include "../../audio/libmad/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
