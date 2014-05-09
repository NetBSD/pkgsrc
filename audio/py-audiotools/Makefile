# $NetBSD: Makefile,v 1.9 2014/05/09 07:36:53 wiz Exp $

DISTNAME=	audiotools-2.20
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=audiotools/2.18/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://audiotools.sourceforge.net/
COMMENT=	Collection of command line audio handling programs
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-urwid-[0-9]*:../../devel/py-urwid

USE_LANGUAGES=	c

REPLACE_PYTHON+=	audiotools/*.py
REPLACE_PYTHON+=	audiotools/py_decoders/*.py
REPLACE_PYTHON+=	audiotools/py_encoders/*.py

EGG_NAME=	Python_Audio_Tools-${PKGVERSION_NOREV}
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 2.20

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
