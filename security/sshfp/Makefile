# $NetBSD: Makefile,v 1.16 2020/05/26 21:18:14 khorben Exp $

DISTNAME=	sshfp-1.2.2
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_GITHUB:=xelerance/}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=xelerange/sshfp/}
COMMENT=	Print ssh host key fingerprint resource records
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-argparse-[0-9]*:../../devel/py-argparse
DEPENDS+=	${PYPKGPREFIX}-dnspython-[0-9]*:../../net/py-dnspython

MANCOMPRESSED=	yes
NO_BUILD=	yes
PYTHON_VERSIONS_ACCEPTED=	27
REPLACE_PYTHON=	dane sshfp

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
