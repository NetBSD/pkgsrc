# $NetBSD: Makefile,v 1.20 2016/03/07 19:40:09 nros Exp $

DISTNAME=	audiotools-3.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=audiotools/}
#MASTER_SITES=	${MASTER_SITE_GITHUB:=tuffy/}
#GITHUB_PROJECT=	python-audio-tools
#GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://audiotools.sourceforge.net/
COMMENT=	Collection of command line audio handling programs
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-urwid-[0-9]*:../../devel/py-urwid

USE_LANGUAGES=		c
USE_TOOLS+=		pkg-config
REPLACE_PYTHON+=	audiotools/*.py
REPLACE_PYTHON+=	audiotools/py_decoders/*.py
REPLACE_PYTHON+=	audiotools/py_encoders/*.py

.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../audio/opusfile/buildlink3.mk"
.include "../../audio/wavpack/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../misc/libcdio-paranoia/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
