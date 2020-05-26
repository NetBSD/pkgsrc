# $NetBSD: Makefile,v 1.18 2020/05/26 22:39:28 adam Exp $

DISTNAME=	sshfp-1.2.2
PKGREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_GITHUB:=xelerance/}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://github.com/xelerance/sshfp
COMMENT=	Print ssh host key fingerprint resource records
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-argparse-[0-9]*:../../devel/py-argparse
DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-ipcalc-[0-9]*:../../net/py-ipcalc

MANCOMPRESSED=	yes
NO_BUILD=	yes
PYTHON_VERSIONS_ACCEPTED=	27
REPLACE_PYTHON=	dane sshfp

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
