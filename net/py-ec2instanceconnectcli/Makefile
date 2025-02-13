# $NetBSD: Makefile,v 1.6 2025/02/13 09:20:06 adam Exp $

DISTNAME=	ec2instanceconnectcli-1.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/ec2instanceconnectcli/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aws/aws-ec2-instance-connect-cli
COMMENT=	AWS EC2 Instance Connect Client
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-botocore>=1.12.179:../../net/py-botocore

USE_LANGUAGES=	# none

post-install:
.for bin in msftp mssh
	cd ${DESTDIR}${PREFIX}/bin && ${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor
	${RM} ${DESTDIR}${PREFIX}/bin/*.cmd

PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
