# $NetBSD: Makefile,v 1.9 2024/05/18 07:27:12 wiz Exp $

DISTNAME=	PyAudio-0.2.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PyA/a/}
PKGREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyAudio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://people.csail.mit.edu/hubert/pyaudio/
COMMENT=	Python bindings for PortAudio
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../audio/portaudio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
