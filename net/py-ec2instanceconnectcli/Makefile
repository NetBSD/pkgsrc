# $NetBSD: Makefile,v 1.5 2022/10/19 13:56:31 nia Exp $

DISTNAME=	ec2instanceconnectcli-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/ec2instanceconnectcli/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aws/aws-ec2-instance-connect-cli
COMMENT=	AWS EC2 Instance Connect Client
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-botocore>=1.12.179:../../net/py-botocore

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

post-install:
.for p in msftp mssh
	${MV} ${DESTDIR}${PREFIX}/bin/${p} ${DESTDIR}${PREFIX}/bin/${p}${PYVERSSUFFIX} || ${TRUE}
.endfor
	${RM} ${DESTDIR}${PREFIX}/bin/*.cmd

.include "../../lang/python/egg.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
