# $NetBSD: Makefile,v 1.15 2019/11/04 21:13:03 rillig Exp $

DISTNAME=	sshfp-1.1.3
PKGREVISION=	5
CATEGORIES=	security net
#MASTER_SITES=	https://www.xelerance.com/software/sshfp/

MAINTAINER=	agc@NetBSD.org
#HOMEPAGE=	https://www.xelerance.com/software/sshfp/
COMMENT=	Print ssh host key fingerprint resource records
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns

MANCOMPRESSED=	yes
NO_BUILD=	yes
REPLACE_PYTHON=	sshfp

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
