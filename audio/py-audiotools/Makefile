# $NetBSD: Makefile,v 1.13 2015/04/13 23:12:40 rodent Exp $

DISTNAME=	audiotools-2.22
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=audiotools/2.18/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://audiotools.sourceforge.net/
COMMENT=	Collection of command line audio handling programs
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-urwid-[0-9]*:../../devel/py-urwid

USE_TOOLS+=	pkg-config
USE_LANGUAGES=		c
REPLACE_PYTHON+=	audiotools/*.py
REPLACE_PYTHON+=	audiotools/py_decoders/*.py
REPLACE_PYTHON+=	audiotools/py_encoders/*.py

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 2.20 or rejected

.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../misc/libcdio-paranoia/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
