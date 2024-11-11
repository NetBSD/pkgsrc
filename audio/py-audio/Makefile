# $NetBSD: Makefile,v 1.11 2024/11/11 07:27:52 wiz Exp $

DISTNAME=	PyAudio-0.2.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PyA/a/}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyAudio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://people.csail.mit.edu/hubert/pyaudio/
COMMENT=	Python bindings for PortAudio
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../audio/portaudio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
