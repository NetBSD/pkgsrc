# $NetBSD: Makefile,v 1.1 2018/04/02 08:41:28 wiz Exp $

DISTNAME=	PyAudio-0.2.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PyA/a/}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyAudio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://people.csail.mit.edu/hubert/pyaudio/
COMMENT=	Python bindings for PortAudio
LICENSE=	mit

.include "../../lang/python/egg.mk"
.include "../../audio/portaudio-devel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
