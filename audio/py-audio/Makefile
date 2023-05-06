# $NetBSD: Makefile,v 1.8 2023/05/06 19:09:03 ryoon Exp $

DISTNAME=	PyAudio-0.2.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PyA/a/}
PKGREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyAudio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://people.csail.mit.edu/hubert/pyaudio/
COMMENT=	Python bindings for PortAudio
LICENSE=	mit

.include "../../lang/python/egg.mk"
.include "../../audio/portaudio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
