# $NetBSD: Makefile,v 1.1.1.1 2008/07/31 10:21:21 agc Exp $

DISTNAME=	sshfp-1.1.3
CATEGORIES=	security net
MASTER_SITES=	http://www.xelerance.com/software/sshfp/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.xelerance.com/
COMMENT=	Print ssh host key fingerprint resource records

DEPENDS+=	 ${PYPKGPREFIX}-dns>=1.6.0:../../net/py-dns

NO_BUILD=			yes
PYTHON_VERSIONS_ACCEPTED=	25 24
PYTHON_PATCH_SCRIPTS=		sshfp

.include "../../lang/python/application.mk"

.include "../../mk/bsd.pkg.mk"
