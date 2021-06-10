# $NetBSD: Makefile,v 1.1 2021/06/10 08:16:49 leot Exp $

DISTNAME=	ec2instanceconnectcli-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/ec2instanceconnectcli/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aws/aws-ec2-instance-connect-cli
COMMENT=	AWS EC2 Instance Connect Client
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-botocore>=1.12.179:../../net/py-botocore
DEPENDS+=	${PYPKGPREFIX}-cryptography>=1.9:../../security/py-cryptography

USE_LANGUAGES=	# none

post-install:
.for p in msftp mssh
	${MV} ${DESTDIR}${PREFIX}/bin/${p} ${DESTDIR}${PREFIX}/bin/${p}${PYVERSSUFFIX} || ${TRUE}
.endfor
	${RM} ${DESTDIR}${PREFIX}/bin/*.cmd

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
